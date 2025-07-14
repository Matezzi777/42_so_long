/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 08:58:19 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/14 16:15:23 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	exit_game("You left by clicking on the cross.", game);
	return (0);
}

int	key_handler(int key, t_game *game)
{
	if (key == XK_Escape)
		exit_game("You left by pressing ESC.", game);
	if (game->finish)
		return (0);
	if (key == XK_Right)
		move_right(game);
	if (key == XK_Left)
		move_left(game);
	if (key == XK_Up)
		move_up(game);
	if (key == XK_Down)
		move_down(game);
	draw_map(game);
	return (0);
}
