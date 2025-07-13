/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:40:18 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 22:48:25 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_move_right(t_game *game, char tile)
{
	game->map[game->player_y][game->player_x + 1] = 'P';
	game->map[game->player_y][game->player_x] = '0';
	if (tile == 'C')
	{
		game->collectibles -= 1;
		if (game->collectibles == 0)
			game->exit_state = OPEN;
	}
	game->player_x += 1;
	ft_printf("Move count : %d.\n", game->moves);
	if (tile == 'E')
		victory(game);
}

void	process_move_left(t_game *game, char tile)
{
	game->map[game->player_y][game->player_x - 1] = 'P';
	game->map[game->player_y][game->player_x] = '0';
	if (tile == 'C')
	{
		game->collectibles -= 1;
		if (game->collectibles == 0)
			game->exit_state = OPEN;
	}
	game->player_x -= 1;
	ft_printf("Move count : %d.\n", game->moves);
	if (tile == 'E')
		victory(game);
}

void	process_move_up(t_game *game, char tile)
{
	game->map[game->player_y - 1][game->player_x] = 'P';
	game->map[game->player_y][game->player_x] = '0';
	if (tile == 'C')
	{
		game->collectibles -= 1;
		if (game->collectibles == 0)
			game->exit_state = OPEN;
	}
	game->player_y -= 1;
	ft_printf("Move count : %d.\n", game->moves);
	if (tile == 'E')
		victory(game);
}

void	process_move_down(t_game *game, char tile)
{
	game->map[game->player_y + 1][game->player_x] = 'P';
	game->map[game->player_y][game->player_x] = '0';
	if (tile == 'C')
	{
		game->collectibles -= 1;
		if (game->collectibles == 0)
			game->exit_state = OPEN;
	}
	game->player_y += 1;
	ft_printf("Move count : %d.\n", game->moves);
	if (tile == 'E')
		victory(game);
}
