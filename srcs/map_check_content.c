/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 00:22:14 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 15:39:13 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	invalid_start(t_list *map)
{
	int		i;
	int		count;
	t_list	*cursor;
	t_map	*line;

	count = 0;
	cursor = map;
	while (cursor)
	{
		line = (t_map *)cursor->content;
		i = -1;
		while (line->line[++i])
			if (line->line[i] == 'P')
				count++;
		cursor = cursor->next;
	}
	if (count < 1)
		return (ft_putstr_fd("Error\nMap does not contain start position.\n",
				STDERR), TRUE);
	if (count > 1)
		return (ft_putstr_fd("Error\nMap contain multiple start positions.\n",
				STDERR), TRUE);
	return (FALSE);
}

t_bool	invalid_exit(t_list *map)
{
	int		i;
	int		count;
	t_list	*cursor;
	t_map	*line;

	count = 0;
	cursor = map;
	while (cursor)
	{
		line = (t_map *)cursor->content;
		i = -1;
		while (line->line[++i])
			if (line->line[i] == 'E')
				count++;
		cursor = cursor->next;
	}
	if (count < 1)
		return (ft_putstr_fd("Error\nMap does not contain exit.\n",
				STDERR), TRUE);
	if (count > 1)
		return (ft_putstr_fd("Error\nMap contain multiple exits.\n",
				STDERR), TRUE);
	return (FALSE);
}

t_bool	missing_collectibles(t_list *map)
{
	int		i;
	int		count;
	t_list	*cursor;
	t_map	*line;

	count = 0;
	cursor = map;
	while (cursor)
	{
		line = (t_map *)cursor->content;
		i = -1;
		while (line->line[++i])
			if (line->line[i] == 'C')
				count++;
		cursor = cursor->next;
	}
	if (count < 1)
		return (ft_putstr_fd("Error\nMap does not contain collectibles.\n",
				STDERR), TRUE);
	return (FALSE);
}

// t_bool	exit_unreachable(t_list *map, int row, int col)
// {

// }

// t_bool	collectible_unreachable(t_list *map)
// {

// }
