/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:50:49 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:34:29 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns x^exp.
	If exp < 0, returns 0
	Does not detect int overflows.
*/
int	ft_pow(int x, int exp)
{
	int	i;
	int	pow;

	if (exp == 0)
		return (1);
	if (x == 0 || exp < 0)
		return (0);
	i = 0;
	pow = x;
	while (++i < exp)
		pow = x * pow;
	return (pow);
}
