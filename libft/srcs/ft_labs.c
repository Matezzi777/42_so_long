/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:27:49 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:21:20 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns the absolute value of a long x.
	Does not detect long overflows.
*/
long	ft_labs(long x)
{
	if (x < 0)
		return (-x);
	return (x);
}
