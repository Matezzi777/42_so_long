/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_big_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:06:34 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 21:51:53 by maxmart2         ###   ########.fr       */
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
	ft_printf("		c = %c | x = %d | y = %d\n", c, x, y);
	if (c == '1')
	{
		ft_printf("			%c\n", c);
		mlx_put_image_to_window(game->mlx, game->win, game->w_sprite,
			x * 64 - 32, y * 64 - 32);
	}
	else if (c == 'C')
	{
		ft_printf("			%c\n", c);
		mlx_put_image_to_window(game->mlx, game->win, game->c_sprite,
			x * 64 - 32, y * 64 - 32);
	}
	else if (c == 'E' && game->exit_state == OPEN)
	{
		ft_printf("			%c OPEN\n", c);
		mlx_put_image_to_window(game->mlx, game->win, game->e_sprites->open,
			x * 64 - 32, y * 64 - 32);
	}
	else if (c == 'E' && game->exit_state == CLOSE)
	{
		ft_printf("			%c CLOSE\n", c);
		mlx_put_image_to_window(game->mlx, game->win, game->e_sprites->close,
			x * 64 - 32, y * 64 - 32);
	}
	else if (c == 'P')
	{
		ft_printf("			%c\n", c);
		draw_player(game, x, y);
	}
	else if (c == '0')
	{
		ft_printf("			%c\n", c);
		mlx_put_image_to_window(game->mlx, game->win, game->g_sprite,
			x * 64 - 32, y * 64 - 32);
	}
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

	ft_printf("Player x : %d\nPlayer y : %d\n", game->player_x, game->player_y);
	draw_y = 0;
	y = game->player_y - 9;
	while (++y < game->player_y + 9)
	{
		draw_x = 0;
		x = game->player_x - 16;
		while (++x < game->player_x + 16)
		{
			if (x < 0 || x > game->width || y < 0 || y >= game->height)
			{
				ft_printf("	(%d, %d) Drawing void in (%d, %d)\n", x, y, draw_x, draw_y);
				draw_sprite(game, 'V', draw_x, draw_y);
			}
			else
			{
				ft_printf("	(%d, %d) Drawing %c in (%d, %d)\n", x, y, game->map[y][x], draw_x, draw_y);
				draw_sprite(game, game->map[y][x], draw_x, draw_y);
			}
			draw_x++;
		}
		draw_y++;
	}
}
