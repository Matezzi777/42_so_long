/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:41:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/17 17:49:21 by maxmart2         ###   ########.fr       */
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

static t_bool	set_player_pos(t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (++row < game->height)
	{
		col = -1;
		while (++col < game->width)
		{
			if (game->map[row][col] == 'P')
			{
				game->player_x = col;
				game->player_y = row;
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

t_game	*load_game(char *file)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	init_game_struct(game);
	game->height = load_map_height(file);
	if (game->height == -1)
		return (ft_error("Unable to load map height."), free(game), NULL);
	if (!load_map(game, file))
		return (ft_error("Unable to load map."), free(game), NULL);
	if (!check_map_content(game))
		return (free_map(game), free(game), NULL);
	if (!load_mlx_data(game))
		return (ft_clean(game), NULL);
	game->player_dir = S;
	game->exit_state = CLOSE;
	if (!set_player_pos(game))
		return (ft_clean(game), NULL);
	game->moves = 0;
	game->finish = FALSE;
	game->big = FALSE;
	if (game->height > WIN_HEIGHT / 64 || game->width > WIN_WIDTH / 64)
		game->big = TRUE;
	return (game);
}
