/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:12:51 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 20:40:15 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	read_map_content(t_game *game);
static t_bool	valid_map_content(t_game *game);
static t_bool	load_map_width(t_game *game);
static int		line_length(char *line);

t_bool	check_map_content(t_game *game)
{
	if (!read_map_content(game))
		return (FALSE);
	if (!valid_map_content(game))
		return (FALSE);
	if (!is_map_closed(game))
		return (ft_error("The map is not closed."), FALSE);
	if (!collectible_reachables(game))
		return (ft_error("At least one collectible is unreachable."), FALSE);
	reset_map(game);
	if (!exit_reachable(game))
		return (ft_error("The exit is unreachable."), FALSE);
	reset_map(game);
	return (TRUE);
}

static t_bool	read_map_content(t_game *game)
{
	int	i;
	int	j;

	if (!load_map_width(game))
		return (ft_error("The map is not a rectangle."), FALSE);
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] == 'C')
				game->collectibles += 1;
			else if (game->map[i][j] == 'E')
				game->exit += 1;
			else if (game->map[i][j] == 'P')
				game->player += 1;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (ft_error("Forbidden character found."), FALSE);
		}
	}
	return (TRUE);
}

static t_bool	load_map_width(t_game *game)
{
	int	i;

	game->width = line_length(game->map[0]);
	i = 0;
	while (game->map[++i])
		if (line_length(game->map[i]) != game->width)
			return (FALSE);
	return (TRUE);
}

static int	line_length(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

static t_bool	valid_map_content(t_game *game)
{
	if (game->player < 1)
		return (ft_error("Missing player."), FALSE);
	if (game->player > 1)
		return (ft_error("Too many spawns."), FALSE);
	if (game->exit < 1)
		return (ft_error("Missing exit."), FALSE);
	if (game->exit > 1)
		return (ft_error("Too many exits."), FALSE);
	if (game->collectibles < 1)
		return (ft_error("Missing collectibles."), FALSE);
	return (TRUE);
}
