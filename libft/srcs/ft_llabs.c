/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:29:58 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:21:34 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns the absolute value of a long long x.
	Does not detect long long overflows.
*/
long long	ft_llabs(long long x)
{
	if (x < 0)
		return (-x);
	return (x);
}
