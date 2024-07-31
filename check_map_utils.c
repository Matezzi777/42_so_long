/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 00:50:12 by mmartina          #+#    #+#             */
/*   Updated: 2024/08/01 01:09:47 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file);

int	count_lines(char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, "O_RDONLY");
	if (fd == -1)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (i);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	if (line)
		free(line);
	return (i);
}
