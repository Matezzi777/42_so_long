/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:41:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 00:58:40 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_length(char *line)
{
	int	i;

	if (!line)
		return (0);
	i  = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

t_bool	load_map_width(t_game *game)
{
	int	i;
	int	j;

	game->width = line_length(game->map[0]);
	i = 0;
	while (game->map[++i])
		if (line_length(game->map[i]) != game->width)
			return (FALSE);
	return (TRUE);
}

t_bool	read_map_content(t_game *game)
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
			{
				game->player += 1;
				game->spawn_x = j;
				game->spawn_y = i;
			}
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (ft_error("Forbidden character found."), FALSE);
		}
	}
	return (TRUE);
}

t_bool	valid_map_content(t_game *game)
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

t_bool	is_map_closed(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (i == 0 && game->map[i][j] != '1')
				return (FALSE);
			else if (i == game->height && game->map[i][j] != '1')
				return (FALSE);
			else if ((j == 0 || j == game->width) && game->map[i][j] != '1')
				return (FALSE);
		}
	}
	return (TRUE);
}

t_bool	collectible_unreachable(t_game *game)
{
	
}

t_bool	exit_unreachable(t_game *game)
{

}

static t_bool	check_map_content(t_game *game)
{
	if (!read_map_content(game))
		return (FALSE);
	if (!valid_map_content(game))
		return (FALSE);
	if (!is_map_closed(game))
		return (ft_error("The map is not closed."), FALSE);
	if (collectible_unreachable(game))
		return (ft_error("At least one collectible is unreachable."), FALSE);
	if (exit_unreachable(game))
		return (ft_error("The exit is unreachable."), FALSE);
	return (TRUE);
}

static int	load_map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	height == 0;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static t_bool	load_map(t_game *game, char *file)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	if (fd == -1 || !game->map)
		return (FALSE);
	i = -1;
	while (++i < game->height + 1)
		game->map[i] = NULL;
	i == -1;
	while (++i < game->height)
	{
		game->map[i] = get_next_line(fd);
		if (!game->map[i])
			break ;
	}
	close(fd);
	if (i != game->height)
		return (free_map(game), FALSE);
	return (TRUE);
}

t_game	*load_game(char *file)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->height = load_map_height(file);
	if (game->height == -1)
		return (ft_error("Unable to load map height."), free(game), NULL);
	if (!load_map(game, file));
		return (ft_error("Unable to load map."), free(game), NULL);
	if (!check_map_content(game))
		return (free_map(game->map), free(game), NULL);
	return (game);
}
