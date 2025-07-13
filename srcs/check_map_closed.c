/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:19:41 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 20:20:35 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	is_closed_top_bottom(char *line, int width);
t_bool	is_closed_middle(char *line, int width);

t_bool	is_map_closed(t_game *game)
{
	int	i;

	i = -1;
	while (game->map[++i])
	{
		if (i == 0 || i == game->height - 1)
		{
			if (!is_closed_top_bottom(game->map[i], game->width))
				return (FALSE);
		}
		else if (!is_closed_middle(game->map[i], game->width))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	is_closed_top_bottom(char *line, int width)
{
	int	i;

	i = -1;
	while (++i < width)
		if (line[i] != '1')
			return (FALSE);
	return (TRUE);
}

t_bool	is_closed_middle(char *line, int width)
{
	if (line[0] == '1' && line[width - 1] == '1')
		return (TRUE);
	return (FALSE);
}
