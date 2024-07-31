/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 22:43:23 by mmartina          #+#    #+#             */
/*   Updated: 2024/08/01 00:00:37 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	is_map_ok;
	
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments.\n");
		return (0);
	}
	is_map_ok = check_map(argv[1]);
	if (is_map_ok)
	{
		manage_error(is_map_ok);
		return (0);
	}
}