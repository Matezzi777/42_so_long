/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:58:30 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/20 22:37:52 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	t_data	img;
	int		color;
	int		t;
	int		r;
	int		g;
	int		b;

	
	mlx = mlx_init();
	window = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
	img = new_image(mlx);
	
	color = create_trgb(0, 200, 100, 50);
	t = get_t(color);
	r = get_r(color);
	g = get_g(color);
	b = get_b(color);

	ft_printf("Color : %d\nt: %d\nr : %d\ng : %d\nb : %d\n", color, t, r, g, b);

	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
}
