/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:25:33 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:22:51 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Free the list and apply the function passed as parameter to free each
	element.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		node = *lst;
		*lst = (*lst)->next;
		free(node);
	}
}
