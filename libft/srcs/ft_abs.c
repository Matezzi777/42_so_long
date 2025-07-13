/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:24:19 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:07:58 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns the absolute value of an integer x.
	Does not detect int overflows.
*/
int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}
