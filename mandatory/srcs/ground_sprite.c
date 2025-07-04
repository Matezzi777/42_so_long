/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:17:48 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 10:32:13 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_ground_sprite(t_game *game)
{
	int	img_width;
	int	img_height;

	game->g_sprite = mlx_xpm_file_to_image(game->mlx,
		"textures/ground.xpm", &img_width, &img_height);
	if (!game->g_sprite)
		return (FALSE);
	return (TRUE);
}
