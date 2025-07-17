/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:49:36 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/17 17:51:41 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_struct(t_game *game)
{
	game->player = 0;
	game->collectibles = 0;
	game->exit = 0;
}
