/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:04:27 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/03 00:34:48 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft.h"

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	int		player;
	int		spawn_x;
	int		spawn_y;
	int		collectibles;
	int		exit;
}				t_game;


// Check arguments
t_bool	valid_arguments(int argc, char **argv);
// Map Parsing
t_game	*load_game(char *file);
// Map Utils
void	free_map(t_game *game);

#endif