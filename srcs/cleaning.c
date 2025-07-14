/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:13:05 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/14 16:42:04 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_esprites(t_game *game);
static void	clean_psprites(t_game *game);

void	ft_clean(t_game *game)
{
	if (game)
	{
		if (game->e_sprites)
			clean_esprites(game);
		if (game->c_sprite)
			mlx_destroy_image(game->mlx, game->c_sprite);
		if (game->g_sprite)
			mlx_destroy_image(game->mlx, game->g_sprite);
		if (game->w_sprite)
			mlx_destroy_image(game->mlx, game->w_sprite);
		if (game->p_sprites)
			clean_psprites(game);
		if (game->v_sprite)
			mlx_destroy_image(game->mlx, game->v_sprite);
		if (game->mlx)
		{
			if (game->win)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		if (game->map)
			free_map(game);
		free(game);
	}
}

static void	clean_esprites(t_game *game)
{
	if (game->e_sprites->close)
		mlx_destroy_image(game->mlx, game->e_sprites->close);
	if (game->e_sprites->open)
		mlx_destroy_image(game->mlx, game->e_sprites->open);
	free(game->e_sprites);
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
	free(game->p_sprites);
}
