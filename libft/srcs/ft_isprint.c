/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:25:20 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:17:37 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character is a printable character.
*/
t_bool	ft_isprint(int c)
{
	if (' ' <= c && c <= '~')
		return (TRUE);
	return (FALSE);
}
