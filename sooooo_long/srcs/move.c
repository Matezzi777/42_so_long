/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:23:05 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 10:03:15 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	game->player_dir = E;
	if (game->map[y][x + 1] == '1'
		|| (game->map[y][x + 1] == 'E' && game->exit_state == CLOSE))
		return ;
	game->moves += 1;
	process_move_right(game, game->map[y][x + 1]);
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	game->player_dir = W;
	if (game->map[y][x - 1] == '1'
		|| (game->map[y][x - 1] == 'E' && game->exit_state == CLOSE))
		return ;
	game->moves += 1;
	process_move_left(game, game->map[y][x - 1]);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	game->player_dir = N;
	if (game->map[y - 1][x] == '1'
		|| (game->map[y - 1][x] == 'E' && game->exit_state == CLOSE))
		return ;
	game->moves += 1;
	process_move_up(game, game->map[y - 1][x]);
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	game->player_dir = S;
	if (game->map[y + 1][x] == '1'
		|| (game->map[y + 1][x] == 'E' && game->exit_state == CLOSE))
		return ;
	game->moves += 1;
	process_move_down(game, game->map[y + 1][x]);
}
