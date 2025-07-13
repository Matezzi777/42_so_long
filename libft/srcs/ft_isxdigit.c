/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:00:52 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:18:46 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character is a character used in hexadecimal.
*/
t_bool	ft_isxdigit(int c)
{
	if (ft_isdigit(c) || ('a' <= c && c <= 'f') || ('A' <= c && c <= 'F'))
		return (TRUE);
	return (FALSE);
}
