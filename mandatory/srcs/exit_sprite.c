/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:12:02 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 10:32:08 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_exit_sprite(t_game *game)
{
	int	img_width;
	int	img_height;

	game->e_sprites = (t_esprites *)malloc(sizeof(t_esprites));
	if (!game->e_sprites)
		return (FALSE);
	game->e_sprites->close = mlx_xpm_file_to_image(game->mlx, "textures/exit_close.xpm",
		&img_width, &img_height);
	if (!game->e_sprites->close)
		return (FALSE);
	game->e_sprites->open = mlx_xpm_file_to_image(game->mlx, "textures/exit_open.xpm",
		&img_width, &img_height);
	if (!game->e_sprites->open)
		return (FALSE);
	return (TRUE);
}
