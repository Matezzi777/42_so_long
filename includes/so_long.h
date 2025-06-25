/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:59:19 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 01:55:20 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

# ifndef SCREEN_WIDTH
#  define SCREEN_WIDTH 800
# endif

# ifndef SCREEN_HEIGHT
#  define SCREEN_HEIGHT 600
# endif

# ifndef WINDOW_NAME
#  define WINDOW_NAME "Hello World !"
# endif

// Data
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// Map
typedef struct s_map
{
	char			*line;
	int				index;
	int				size;
}				t_map;

// Graphics
int		create_trgb(int t, int r, int g, int b);
int		get_t(int color);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);
void	my_pixel_put(t_data *data, int x, int y, int color);
t_data	new_image(void *mlx);

// Parsing
t_list	*parse_arguments(int argc, char **argv);
t_list	*get_map(int fd);
t_bool	valid_map(t_list *map);

// Map
t_bool	map_not_rect(t_list *map);
t_bool	map_not_closed(t_list *map);
t_bool	invalid_start(t_list *map);
t_bool	invalid_exit(t_list *map);
t_bool	missing_collectibles(t_list *map);
char	get_map_char(t_list *map, int row, int col);
char	*get_map_line(t_list *map, int index);

// Free
void	free_map_line(void *line);
void	clean_free(t_list *map);

#endif