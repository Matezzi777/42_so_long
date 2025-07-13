/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:12:22 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/13 23:21:32 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	valid_arguments(int argc, char **argv)
{
	int	fd;
	int	len;

	if (argc < 2)
		return (ft_error("Too few arguments (1 needed)."), FALSE);
	if (argc > 2)
		return (ft_error("Too many arguments (1 needed)."), FALSE);
	len = ft_strlen(argv[1]);
	if ((len < 5) || (ft_strncmp(&argv[1][len - 4], ".ber", 4) != 0))
		return (ft_error("Wrong map extension (.ber needed)."), FALSE);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error("Unable to open the file."), FALSE);
	close(fd);
	return (TRUE);
}
