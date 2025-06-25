/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:16:10 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 15:39:30 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	valid_map(t_list *map)
{
	if (map_not_rect(map))
		return (FALSE);
	// if (invalid_character(map))
	// 	return (FALSE);
	if (map_not_closed(map))
		return (FALSE);
	if (invalid_start(map))
		return (FALSE);
	if (invalid_exit(map))
		return (FALSE);
	if (missing_collectibles(map))
		return (FALSE);
	// if (exit_unreachable(map, get_player_row(map), get_player_col(map)))
	// 	return (FALSE);
	// if (collectible_unreachable(map))
	// 	return (FALSE);
	return (TRUE);
}
