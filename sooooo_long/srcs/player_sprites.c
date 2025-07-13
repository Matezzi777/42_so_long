/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:35:40 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 23:07:31 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_player_sprites(t_game *game)
{
	int	img_width;
	int	img_height;

	game->p_sprites = (t_psprites *)malloc(sizeof(t_psprites));
	if (!game->p_sprites)
		return (FALSE);
	game->p_sprites->idle_east = mlx_xpm_file_to_image(game->mlx,
			"textures/player_idle_east.xpm", &img_width, &img_height);
	if (!game->p_sprites->idle_east)
		return (FALSE);
	game->p_sprites->idle_west = mlx_xpm_file_to_image(game->mlx,
			"textures/player_idle_west.xpm", &img_width, &img_height);
	if (!game->p_sprites->idle_west)
		return (FALSE);
	game->p_sprites->idle_north = mlx_xpm_file_to_image(game->mlx,
			"textures/player_idle_north.xpm", &img_width, &img_height);
	if (!game->p_sprites->idle_north)
		return (FALSE);
	game->p_sprites->idle_south = mlx_xpm_file_to_image(game->mlx,
			"textures/player_idle_south.xpm", &img_width, &img_height);
	if (!game->p_sprites->idle_south)
		return (FALSE);
	return (TRUE);
}
