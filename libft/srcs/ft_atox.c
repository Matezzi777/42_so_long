/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 02:58:49 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/23 03:07:16 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_atox(unsigned char c, t_bool upper)
{
	char	*bin;
	char	*charset;

	bin = (char *)malloc(3 * sizeof(char));
	if (!bin)
		return (NULL);
	if (upper)
		charset = "0123456789ABCDEF";
	else
		charset = "0123456789abcdef";
	bin[0] = charset[c / 16];
	bin[1] = charset[c % 16];
	bin[2] = '\0';
	return (bin);
}
