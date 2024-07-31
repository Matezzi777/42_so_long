/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:51:13 by mmartina          #+#    #+#             */
/*   Updated: 2024/08/01 01:33:14 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	manage_error_map(int error);
int		check_map(char *map);
int		check_map_name(char *map);
int		check_map_content(int map_fd);
int		check_first_line(char *ligne);

int		check_map(char *map)
{
	int	map_fd;
	int	check_content;
	int	nb_lines;

	map_fd = open(map, "O_RDONLY");
	if (map_fd == -1)
		return (1); //Fichier introuvable ou échec d'ouverture
	if (check_map_name(map))
		return (2); //Nom de carte incorrect
	nb_lines = count_lines(map);
	
}

void	manage_error_map(int error)
{
	// Erreur 1 : Fichier introuvable ou échec d'ouverture
	// Erreur 2 : Nom de carte incorrect
	// Erreur 3 : Map vide
	// Erreur 4 : Map not closed
}

int		check_map_name(char *map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map);
	if ((len < 5) || (map[len-4] != '.') || (map[len-3] != 'b') || (map[len-2] != 'e') || (map[len-1] != 'r'))
		return (1);
	else
		return (0);
}

int		check_map_content(int map_fd)
{
	char	*line;
	int		len;
	int		line_check;

	line = get_next_line(map_fd);
	if (!line)
		return (3); //Map vide
	len = ft_strlen(line);
	if (check_first_line(line))
		return (4); //Map not closed
	while (line)
	{
		free(line);
		line = get_next_line(map_fd);
		line_check = check_line(line, len);
	}
	if (line)
		free(line);
}

int		check_first_line(char *ligne)
{
	int	i;

	i = 0;
	while (ligne[i+1])
	{
		if (ligne[i] != '1')
			return (1); //Map not closed
		i++;
	}
	return (0);
}