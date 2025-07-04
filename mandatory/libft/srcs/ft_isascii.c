/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:25:10 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:16:00 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character is contained in the ASCII table.
*/
t_bool	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (TRUE);
	return (FALSE);
}
