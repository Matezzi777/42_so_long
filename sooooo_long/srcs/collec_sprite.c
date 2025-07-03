/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collec_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:15:15 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 23:17:42 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_collec_sprite(t_game *game)
{
	game->c_sprite = mlx_xpm_file_to_image(game->mlx,
		"textures/collectible_pokeball.xpm", NULL, NULL);
	if (!game->c_sprite)
		return (FALSE);
	return (TRUE);
}
