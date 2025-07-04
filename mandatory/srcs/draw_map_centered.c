/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_centered.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:27:31 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 20:10:10 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background_centered(t_game *game)
{
	int	x;
	int	y;

	y = game->player_y - 8 - 1;
	while (++y < 17)
	{
		x = game->player_x - 15 - 1;
		while (++x < 31)
		{
			if (x < 0 || x > game->width || y < 0 || y > game->height)
				mlx_put_image_to_window(game->mlx, game->win, game->v_sprite,
					WIN_WIDTH / 2 + (x * 64) - 32, WIN_HEIGHT / 2 + (y * 64));
			else if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->w_sprite,
					WIN_WIDTH / 2 + (x * 64) - 32, WIN_HEIGHT / 2 + (y * 64));
			else
				mlx_put_image_to_window(game->mlx, game->win, game->g_sprite,
					WIN_WIDTH / 2 + (x * 64) - 32, WIN_HEIGHT / 2 + (y * 64));
		}
	}
}

void	draw_collectibles_centered(t_game *game)
{
	int	x;
	int	y;

	y = game->player_y - 8 - 1;
	while (++y < 17)
	{
		x = game->player_x - 15 - 1;
		while (++x < 31)
		{
			if (x > 0 || x < game->width || y > 0 || y < game->height)
				if (game->map[y][x] == 'C')
					mlx_put_image_to_window(game->mlx, game->win,
						game->c_sprite, WIN_WIDTH / 2 + (x * 64) - 32,
						WIN_HEIGHT / 2 + (y * 64));
		}
	}
}

void	draw_exit_centered(t_game *game)
{
	int	x;
	int	y;

	y = game->player_y - 8 - 1;
	while (++y < 17)
	{
		x = game->player_x - 15 - 1;
		while (++x < 31)
		{
			if (x > 0 || x < game->width || y > 0 || y < game->height)
			{
				if (game->map[y][x] == 'E' && game->exit_state == OPEN)
					mlx_put_image_to_window(game->mlx, game->win,
						game->e_sprites->open, WIN_WIDTH / 2 + (x * 64) - 32,
						WIN_HEIGHT / 2 + (y * 64));
				else if (game->map[y][x] == 'E' && game->exit_state == CLOSE)
					mlx_put_image_to_window(game->mlx, game->win,
						game->e_sprites->close, WIN_WIDTH / 2 + (x * 64) - 32,
						WIN_HEIGHT / 2 + (y * 64));
			}
		}
	}
}

void	draw_player_centered(t_game *game)
{
	if (game->player_dir == N)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_north,
			WIN_WIDTH / 2 - 32, WIN_HEIGHT / 2 - 32);
	else if (game->player_dir == S)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_south,
			WIN_WIDTH / 2 - 32, WIN_HEIGHT / 2 - 32);
	else if (game->player_dir == W)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_west,
			WIN_WIDTH / 2 - 32, WIN_HEIGHT / 2 - 32);
	else if (game->player_dir == E)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_east,
			WIN_WIDTH / 2 - 32, WIN_HEIGHT / 2 - 32);
}
