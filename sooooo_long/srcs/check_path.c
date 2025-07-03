/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:16:44 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 20:18:17 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	can_reach(t_game *game, int x, int y, char *ruleset);

t_bool	collectible_reachables(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == 'C')
				if (!can_reach(game, x, y, "P0C"))
					return (FALSE);
	}
	return (TRUE);
}

t_bool	exit_reachable(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
				if (!can_reach(game, x, y, "EP0C"))
					return (FALSE);
		}
	}
	return (TRUE);
}

static t_bool	can_reach(t_game *game, int x, int y, char *ruleset)
{
	if (!game->map || x < 0 || y < 0 || !ruleset || ft_strlen(ruleset) < 2
		|| x > game->width - 1 || y > game->height - 1)
		return (FALSE);
	if (game->map[y][x] == ruleset[0])
		return (TRUE);
	if (!ft_strchr(ruleset, game->map[y][x]))
		return (FALSE);
	if (game->map[y][x] == '0')
		game->map[y][x] = 'A';
	if (game->map[y][x] == 'P')
		game->map[y][x] = 'B';
	if (game->map[y][x] == 'E')
		game->map[y][x] = 'D';
	if (game->map[y][x] == 'C')
		game->map[y][x] = 'F';
	if (can_reach(game, x + 1, y, ruleset))
		return (TRUE);
	else if (can_reach(game, x, y + 1, ruleset))
		return (TRUE);
	else if (can_reach(game, x - 1, y, ruleset))
		return (TRUE);
	else if (can_reach(game, x, y - 1, ruleset))
		return (TRUE);
	return (FALSE);
}
