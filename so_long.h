/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:51:25 by mmartina          #+#    #+#             */
/*   Updated: 2024/08/01 01:02:02 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

// Libraries
# include <mlx.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

// Sources
//check_map.c
void	manage_error_map(int error);
int		check_map(char *map);
int		check_map_name(char *map);
int		check_map_content(int map_fd);
int		check_first_line(char *ligne);
//check_map_utils.c
int		count_lines(char *file);

#endif