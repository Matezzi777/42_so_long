/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:13:05 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 22:46:51 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_psprites(t_game *game);
static void	clean_psprites_walk(t_game *game);

void	ft_clean(t_game *game)
{
	if (game->e_sprite)
		mlx_destroy_image(game->mlx, game->e_sprite);
	if (game->c_sprite)
		mlx_destroy_image(game->mlx, game->c_sprite);
	if (game->g_sprite)
		mlx_destroy_image(game->mlx, game->g_sprite);
	if (game->w_sprite)
		mlx_destroy_image(game->mlx, game->w_sprite);
	if (game->p_sprites)
		clean_psprites(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->map)
		free_map(game);
	free(game);
}

static void	clean_psprites(t_game *game)
{
	if (game->p_sprites->idle_east)
		mlx_destroy_image(game->mlx, game->p_sprites->idle_east);
	if (game->p_sprites->idle_west)
		mlx_destroy_image(game->mlx, game->p_sprites->idle_west);
	if (game->p_sprites->idle_north)
		mlx_destroy_image(game->mlx, game->p_sprites->idle_north);
	if (game->p_sprites->idle_south)
		mlx_destroy_image(game->mlx, game->p_sprites->idle_south);
	clean_psprites_walk(game);
	free(game->p_sprites);
}

static void	clean_psprites_walk(t_game *game)
{
	if (game->p_sprites->walk_easta)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_easta);
	if (game->p_sprites->walk_westa)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_westa);
	if (game->p_sprites->walk_northa)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_northa);
	if (game->p_sprites->walk_southa)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_southa);
	if (game->p_sprites->walk_eastb)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_eastb);
	if (game->p_sprites->walk_westb)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_westb);
	if (game->p_sprites->walk_northb)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_northb);
	if (game->p_sprites->walk_southb)
		mlx_destroy_image(game->mlx, game->p_sprites->walk_southb);
}
