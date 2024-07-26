/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 11:53:50 by mmartina          #+#    #+#             */
/*   Updated: 2024/07/26 11:53:56 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
}	data_t;

int	main(void)
{
	data_t	data;

	if((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}