/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:53:26 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/14 16:42:30 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	init_window(t_game *game)
{
	if (game->width < WIN_WIDTH / 64 && game->height < WIN_HEIGHT / 64)
		game->win = mlx_new_window(game->mlx,
				game->width * 64, game->height * 64, WIN_NAME);
	else
		game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!game->win)
		return (FALSE);
	return (TRUE);
}

static t_bool	load_sprites(t_game *game)
{
	if (!load_player_sprites(game))
		return (ft_error("Player Sprites."), FALSE);
	if (!load_exit_sprite(game))
		return (ft_error("Exit Sprite."), FALSE);
	if (!load_collec_sprite(game))
		return (ft_error("Collec Sprite."), FALSE);
	if (!load_ground_sprite(game))
		return (ft_error("Ground Sprite."), FALSE);
	if (!load_wall_sprite(game))
		return (ft_error("Wall Sprite."), FALSE);
	if (!load_void_sprite(game))
		return (ft_error("Void Sprite."), FALSE);
	return (TRUE);
}

t_bool	load_mlx_data(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("Problem during mlx initialization."), FALSE);
	if (!init_window(game))
		return (ft_error("Problem during window creation."),
			FALSE);
	if (!load_sprites(game))
		return (ft_error("Problem during sprites loading."),
			FALSE);
	return (TRUE);
}
