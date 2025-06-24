/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 18:48:58 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/24 21:18:32 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*parse_arguments(int argc, char **argv)
{
	int		fd;
	t_list	*map;

	if (argc < 2)
		return (ft_putstr_fd("Not enough arguments.\nUse : ./so_long <map>\n",
				STDERR), NULL);
	if (argc > 2)
		return (ft_putstr_fd("Too much arguments.\nUse : ./so_long <map>\n",
				STDERR), NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Unable to open this file.\n", STDERR), NULL);
	map = get_map(fd);
	close(fd);
	if (!map)
		return (ft_putstr_fd("An error occured while reading the file.\n",
				STDERR), NULL);
	return (map);
}
