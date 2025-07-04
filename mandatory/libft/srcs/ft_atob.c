/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 02:38:38 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:07:54 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns a string containing the value converted to binary.
*/
char	*ft_atob(unsigned char c)
{
	int		i;
	char	*bin;

	bin = (char *)malloc(9 * sizeof(char));
	if (!bin)
		return (NULL);
	i = 0;
	while (i < 8)
	{
		bin[7 - i] = c % 2 + '0';
		c = c / 2;
		i++;
	}
	bin[i] = '\0';
	return (bin);
}
