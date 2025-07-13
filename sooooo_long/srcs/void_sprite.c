/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:39:37 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 15:40:54 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_void_sprite(t_game *game)
{
	int	img_width;
	int	img_height;

	game->v_sprite = mlx_xpm_file_to_image(game->mlx,
		"textures/void.xpm", &img_width, &img_height);
	if (!game->v_sprite)
		return (FALSE);
	return (TRUE);
}
