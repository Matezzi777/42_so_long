/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:10:35 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:18:01 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character is a punctuation character.
*/
t_bool	ft_ispunct(int c)
{
	if (('!' <= c && c <= '/') || (':' <= c && c <= '@')
		|| ('[' <= c && c <= '`') || ('{' <= c && c <= '~'))
		return (TRUE);
	return (FALSE);
}
