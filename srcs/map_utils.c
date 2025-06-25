/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 01:48:11 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 01:54:45 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_map_line(t_list *map, int index)
{
	t_list	*cursor;
	t_map	*line;

	if (index < 0)
		return (NULL);
	cursor = map;
	while (cursor)
	{
		line = (t_map *)cursor->content;
		if (line->index == index)
			return (line->line);
		cursor = cursor->next;
	}
	return (NULL);
}

char	get_map_char(t_list *map, int row, int col)
{
	int		i;
	char	*line;

	line = get_map_line(map, row);
	if (!line)
		return (0);
	i = -1;
	while (line[++i])
		if (i == col)
			return (line[i]);
	return (0);
}
