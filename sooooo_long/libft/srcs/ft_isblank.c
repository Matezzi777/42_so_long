/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:07:51 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:16:29 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character does not have a symbol.
*/
t_bool	ft_isblank(int c)
{
	if (c == '\t' || c == ' ')
		return (TRUE);
	return (FALSE);
}
