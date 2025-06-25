/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:58:30 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/25 00:40:12 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	ft_print_map(t_list *map)
{
	t_list	*cursor;
	t_map	*map_line;

	cursor = map;
	while (cursor)
	{
		map_line = (t_map *)cursor->content;
		ft_printf("%d: %s (%d)\n", map_line->index, map_line->line,
			map_line->size);
		cursor = cursor->next;
	}
}

int	main(int argc, char **argv)
{
	t_list	*map;
	// void	*mlx;
	// void	*window;
	// t_data	img;

	map = parse_arguments(argc, argv);
	if (!map)
		return (0);
	ft_print_map(map);
	if (!valid_map(map))
		return (0);
	// mlx = mlx_init();
	// window = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME);
	// img = new_image(mlx);

	// mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	// mlx_loop(mlx);
	clean_free(map);
	return (0);
}
