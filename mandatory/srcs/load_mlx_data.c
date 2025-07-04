/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_mlx_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:53:26 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 19:32:16 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	init_window(t_game *game)
{
	int	width;
	int	height;

	if (game->width < WIN_WIDTH / 64)
		width = game->width * 64;
	else
		width = WIN_WIDTH;
	if (game->height < WIN_HEIGHT / 64)
		height = game->height * 64;
	else
		height = WIN_HEIGHT;
	game->win = mlx_new_window(game->mlx, width, height, WIN_NAME);
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
	if (game->big_map)
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
