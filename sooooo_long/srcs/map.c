/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:04:01 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 05:43:49 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game)
{
	int	x;

	ft_putchar_fd('\n', STDOUT);
	x = -1;
	while (game->map[++x])
		ft_printf("%s", game->map[x]);
	ft_putchar_fd('\n', STDOUT);
}

void	reset_map(t_game *game)
{
	int	i;
	int	j;

	if (!game->map)
		return ;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'A')
				game->map[i][j] = '0';
			if (game->map[i][j] == 'B')
				game->map[i][j] = 'P';
			if (game->map[i][j] == 'D')
				game->map[i][j] = 'E';
			if (game->map[i][j] == 'F')
				game->map[i][j] = 'C';
		}
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->height + 1)
		free(game->map[i]);
	free(game->map);
}
