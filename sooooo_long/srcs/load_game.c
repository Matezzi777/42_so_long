/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:41:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 22:17:50 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_map_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	height = 0;
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

	fd = open(file, O_RDONLY);
	game->map = (char **)malloc((game->height + 1) * sizeof(char *));
	if (fd == -1 || !game->map)
		return (FALSE);
	i = -1;
	while (++i < game->height + 1)
		game->map[i] = NULL;
	i = -1;
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
	if (!load_map(game, file))
		return (ft_error("Unable to load map."), free(game), NULL);
	if (!check_map_content(game))
		return (free_map(game), free(game), NULL);
	if (!load_mlx_data(game))
		return (free_map(game), free(game), NULL);
	return (game);
}
