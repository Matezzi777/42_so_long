/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:35:40 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 22:47:55 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	load_player_idle_sprites(t_game *game);
static t_bool	load_player_walk_sprites_a(t_game *game);
static t_bool	load_player_walk_sprites_b(t_game *game);

t_bool	load_player_sprites(t_game *game)
{
	game->p_sprites = (t_psprites *)malloc(sizeof(t_psprites));
	if (!game->p_sprites)
		return (FALSE);
	if (!load_player_idle_sprites(game))
		return (FALSE);
	if (!load_player_walk_sprites_a(game))
		return (FALSE);
	if (!load_player_walk_sprites_b(game))
		return (FALSE);
	return (TRUE);
}

static t_bool	load_player_idle_sprites(t_game *game)
{
	int	img_width;
	int	img_height;

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

static t_bool	load_player_walk_sprites_a(t_game *game)
{
	int	img_width;
	int	img_height;

	game->p_sprites->walk_easta = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_east1.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_easta)
		return (FALSE);
	game->p_sprites->walk_westa = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_west1.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_westa)
		return (FALSE);
	game->p_sprites->walk_northa = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_north1.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_northa)
		return (FALSE);
	game->p_sprites->walk_southa = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_south1.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_southa)
		return (FALSE);
	return (TRUE);
}

static t_bool	load_player_walk_sprites_b(t_game *game)
{
	int	img_width;
	int	img_height;

	game->p_sprites->walk_eastb = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_east2.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_eastb)
		return (FALSE);
	game->p_sprites->walk_westb = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_west2.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_westb)
		return (FALSE);
	game->p_sprites->walk_northb = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_north2.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_northb)
		return (FALSE);
	game->p_sprites->walk_southb = mlx_xpm_file_to_image(game->mlx,
			"textures/player_walk_south2.xpm", &img_width, &img_height);
	if (!game->p_sprites->walk_southb)
		return (FALSE);
	return (TRUE);
}
