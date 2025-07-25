/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:06:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/25 06:35:36 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory(t_game *game)
{
	game->finish = TRUE;
	ft_printf("Victory !\nYou won in %d moves.\n", game->moves);
	exit_game(NULL, game);
}
