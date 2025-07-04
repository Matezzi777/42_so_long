/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:03:59 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/04 10:25:43 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!valid_arguments(argc, argv))
		return (0);
	game = load_game(argv[1]);
	if (!game)
		return (0);
	draw_map(game);
	mlx_key_hook(game->win, key_handler, game);
	mlx_hook(game->win, ON_DESTROY, 0, on_destroy, game);
	mlx_loop(game->mlx);
}
