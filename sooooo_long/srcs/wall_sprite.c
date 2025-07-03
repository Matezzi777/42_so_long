/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:09:47 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 23:21:20 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

t_bool	load_wall_sprite(t_game *game)
{
	game->w_sprite = mlx_xpm_file_to_image(game->mlx,
		"textures/wall.xpm", NULL, NULL);
	if (!game->w_sprite)
		return (FALSE);
	return (TRUE);
}
