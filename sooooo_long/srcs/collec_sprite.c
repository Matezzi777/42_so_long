/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:15:15 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 22:51:09 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_collec_sprite(t_game *game)
{
	int	img_width;
	int	img_height;

	game->c_sprite = mlx_xpm_file_to_image(game->mlx,
			"textures/pokeball.xpm", &img_width, &img_height);
	if (!game->c_sprite)
		return (FALSE);
	return (TRUE);
}
