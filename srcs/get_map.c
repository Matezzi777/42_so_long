/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:20:03 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/24 23:40:44 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static t_map	*create_map_line(char *line, int index)
{
	t_map	*map_line;

	map_line = (t_map *)malloc(sizeof(t_map));
	if (!map_line)
		return (NULL);
	map_line->line = line;
	map_line->index = index;
	map_line->size = ft_strlen(line) - 1;
	return (map_line);
}

static void	correct_last_line_length(t_list **map)
{
	t_list	*cursor;
	t_map	*map_line;

	if (!map || !*map)
		return ;
	cursor = *map;
	while (cursor->next)
		cursor = cursor->next;
	map_line = (t_map *)(cursor->content);
	map_line->size += 1;
}

t_list	*get_map(int fd)
{
	int		index;
	char	*line;
	t_map	*map_line;
	t_list	*map;

	map = NULL;
	index = -1;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map_line = create_map_line(line, ++index);
		if (!map_line)
			return (ft_lstclear(&map, free_map_line), NULL);
		ft_lstadd_back(&map, ft_lstnew((void *)map_line));
	}
	correct_last_line_length(&map);
	return (map);
}
