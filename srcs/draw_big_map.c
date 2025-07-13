/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_big_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:06:34 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 22:50:13 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_player(t_game *game, int x, int y)
{
	if (game->player_dir == N)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_north, x * 64 - 32, y * 64 - 32);
	else if (game->player_dir == W)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_west, x * 64 - 32, y * 64 - 32);
	else if (game->player_dir == E)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_east, x * 64 - 32, y * 64 - 32);
	else
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_sprites->idle_south, x * 64 - 32, y * 64 - 32);
}

static void	draw_sprite(t_game *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->w_sprite,
			x * 64 - 32, y * 64 - 32);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->c_sprite,
			x * 64 - 32, y * 64 - 32);
	else if (c == 'E' && game->exit_state == OPEN)
		mlx_put_image_to_window(game->mlx, game->win, game->e_sprites->open,
			x * 64 - 32, y * 64 - 32);
	else if (c == 'E' && game->exit_state == CLOSE)
		mlx_put_image_to_window(game->mlx, game->win, game->e_sprites->close,
			x * 64 - 32, y * 64 - 32);
	else if (c == 'P')
		draw_player(game, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->g_sprite,
			x * 64 - 32, y * 64 - 32);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->v_sprite,
			x * 64 - 32, y * 64 - 32);
}

void	draw_big_map(t_game *game)
{
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;

	draw_y = 0;
	y = game->player_y - 6;
	while (++y < game->player_y + 6)
	{
		draw_x = 0;
		x = game->player_x - 11;
		while (++x < game->player_x + 11)
		{
			if (x < 0 || x > game->width || y < 0 || y >= game->height)
				draw_sprite(game, 'V', draw_x, draw_y);
			else
				draw_sprite(game, game->map[y][x], draw_x, draw_y);
			draw_x++;
		}
		draw_y++;
	}
}
