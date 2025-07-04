/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 06:29:00 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 20:41:52 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_background(t_game *game)
{
	int	col;
	int	row;

	row = -1;
	while (++row < game->height)
	{
		col = -1;
		while (++col < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->g_sprite, col * 64 + 1, row * 64 + 1);
			if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->w_sprite, col * 64 + 1, row * 64 + 1);
		}
	}
}

static void	draw_collectibles(t_game *game)
{
	int	col;
	int	row;

	row = -1;
	while (++row < game->height)
	{
		col = -1;
		while (++col < game->width)
			if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->c_sprite, col * 64 + 1, row * 64 + 1);
	}

}

static void	draw_exit(t_game *game)
{
	int	col;
	int	row;

	row = -1;
	while (++row < game->height)
	{
		col = -1;
		while (++col < game->width)
		{
			if (game->map[row][col] == 'E')
			{
				if (game->exit_state == CLOSE)
					mlx_put_image_to_window(game->mlx, game->win, game->e_sprites->close, col * 64 + 1, row * 64 + 1);
				else if (game->exit_state == OPEN)
					mlx_put_image_to_window(game->mlx, game->win, game->e_sprites->open, col * 64 + 1, row * 64 + 1);
			}
		}
	}
}

static void	draw_player(t_game *game)
{
	int	col;
	int	row;

	row = -1;
	while (++row < game->height)
	{
		col = -1;
		while (++col < game->width)
		{
			if (game->map[row][col] == 'P')
			{
				if (game->player_dir == N)
					mlx_put_image_to_window(game->mlx, game->win, game->p_sprites->idle_north, col * 64 + 1, row * 64 + 1);
				else if (game->player_dir == S)
					mlx_put_image_to_window(game->mlx, game->win, game->p_sprites->idle_south, col * 64 + 1, row * 64 + 1);
				if (game->player_dir == W)
					mlx_put_image_to_window(game->mlx, game->win, game->p_sprites->idle_west, col * 64 + 1, row * 64 + 1);
				if (game->player_dir == E)
					mlx_put_image_to_window(game->mlx, game->win, game->p_sprites->idle_east, col * 64 + 1, row * 64 + 1);
			}
		}
	}
}

void	draw_map(t_game *game)
{
	draw_background(game);
	draw_collectibles(game);
	draw_exit(game);
	draw_player(game);
}
