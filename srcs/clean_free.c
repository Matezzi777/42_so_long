/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 22:40:03 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/24 22:40:39 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_line(void *line)
{
	t_map	*map_line;

	map_line = (t_map *)line;
	free(map_line->line);
	free(map_line);
}
