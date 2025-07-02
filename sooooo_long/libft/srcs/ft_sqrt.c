/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:50:21 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:38:25 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns the square root of a number x.
	Returns FALSE if the root is a float.
*/
unsigned int	ft_sqrt(unsigned int x)
{
	unsigned int	i;

	i = 0;
	while (i * i < x)
		i++;
	if (i * i == x)
		return (i);
	return (FALSE);
}
