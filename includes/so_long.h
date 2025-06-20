/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:59:19 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/20 22:35:09 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_pixel_put(t_data *data, int x, int y, int color);
t_data	new_image(void *mlx);
int		create_trgb(int t, int r, int g, int b);
int		get_t(int color);
int		get_r(int color);
int		get_g(int color);
int		get_b(int color);

#endif