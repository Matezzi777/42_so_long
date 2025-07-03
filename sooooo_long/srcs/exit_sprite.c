/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:12:02 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 23:15:30 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	load_exit_sprite(t_game *game)
{
	game->e_sprite = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
		NULL, NULL);
	if (!game->e_sprite)
		return (FALSE);
	return (TRUE);
}
