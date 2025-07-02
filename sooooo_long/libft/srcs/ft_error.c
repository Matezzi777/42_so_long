/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:03:16 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 22:08:45 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Prints a string in the standard error, followed by a newline.
*/
void	ft_error(char *str)
{
	ft_putendl_fd("Error", STDERR);
	ft_putendl_fd(str, STDERR);
}
