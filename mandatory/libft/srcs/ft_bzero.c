/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:24:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:12:56 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Fill a block of memory with '\0'.
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*cursor;

	cursor = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		cursor[i] = '\0';
		i++;
	}
}
