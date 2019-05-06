/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:54:31 by sstark            #+#    #+#             */
/*   Updated: 2019/01/13 15:30:07 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *prev;
	t_list *new;

	first = NULL;
	if (lst)
	{
		first = f(lst);
		if (first == NULL)
			return (NULL);
		prev = first;
		lst = lst->next;
	}
	while (lst)
	{
		new = f(lst);
		if (new == NULL)
			return (NULL);
		prev->next = new;
		prev = prev->next;
		lst = lst->next;
	}
	return (first);
}
