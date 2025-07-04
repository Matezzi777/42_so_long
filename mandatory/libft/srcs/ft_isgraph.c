/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:09:03 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:17:19 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character does have a symbol.
*/
t_bool	ft_isgraph(int c)
{
	if ('!' <= c && c <= '~')
		return (TRUE);
	return (FALSE);
}
