/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:06:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:16:40 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character is a control character.
*/
t_bool	ft_iscntrl(int c)
{
	if (c < ' ' || c == 127)
		return (TRUE);
	return (FALSE);
}
