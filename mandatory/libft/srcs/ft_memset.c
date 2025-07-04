/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:26:08 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:33:21 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Set a block of memory to c value.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*a;

	a = s;
	i = 0;
	while (i < n)
	{
		*a = c;
		a++;
		i++;
	}
	return (s);
}
