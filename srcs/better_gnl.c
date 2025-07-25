/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_gnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 06:19:41 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/25 06:41:05 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*add_char_to_line(char *line, char c);

char	*better_gnl(int fd)
{
	int		bytes;
	char	buffer[2];
	char	*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || read(fd, NULL, 0) < 0)
		return (NULL);
	while (TRUE)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] == '\n')
			break ;
		line = add_char_to_line(line, buffer[0]);
	}
	if (line)
		line = add_char_to_line(line, '\0');
	return (line);
}

static char	*add_char_to_line(char *line, char c)
{
	int		i;
	char	*result;

	if (!line)
	{
		result = (char *)malloc(2 * sizeof(char));
		if (!result)
			return (NULL);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	result = (char *)malloc((ft_strlen(line) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (line[++i])
		result[i] = line[i];
	result[i] = c;
	result[i + 1] = '\0';
	free(line);
	return (result);
}
