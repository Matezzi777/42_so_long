/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:22:10 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 00:54:35 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	map_not_rect(t_list *map)
{
	t_map	*line;
	t_list	*cursor;
	int		length;

	line = (t_map *)map->content;
	length = line->size;
	cursor = map;
	while (cursor->next)
	{
		cursor = cursor->next;
		line = (t_map *)cursor->content;
		if (line->size != length)
			return (ft_putstr_fd("Error\nMap not rectangular.\n", STDERR),
					TRUE);
	}
	return (FALSE);
}

t_bool	map_not_closed(t_list *map)
{
	int		i;
	t_map	*line;
	t_list	*cursor;

	cursor = map;
	while (cursor)
	{
		line = (t_map *)cursor->content;
		if (line->index == 0 || !cursor->next)
		{
			i = -1;
			while (line->line[++i])
				if (line->line[i] != '1')
					return (ft_putstr_fd("Error\nMap not closed.\n", STDERR),
							TRUE);
		}
		else
		{
			if (line->line[0] != '1' || line->line[(line->size)-1] != '1')
				return (ft_putstr_fd("Error\nMap not closed.\n", STDERR),
						TRUE);
		}
		cursor = cursor->next;
	}
	return (FALSE);
}
