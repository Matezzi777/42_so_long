/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 01:58:56 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 02:08:30 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player_row(t_list *map)
{
	int		i;
	int		index;
	char	*line;

	index = 0;
	while (TRUE)
	{
		line = get_map_line(map, index);
		if (!line)
			break ;
		i = -1;
		while (line[++i])
			if (line[i] == 'P')
				return (index);
		index++;
	}
	return (-1);
}

int	get_player_col(t_list *map)
{
	int		i;
	int		row;
	char	*line;

	row = get_player_row(map);
	if (row == -1)
		return (-1);
	line = get_map_line(map, row);
	if (!line)
		return (-1);
	i = -1;
	while (line[++i])
		if (line[i] == 'P')
			return (i);
	return (-1);
}
