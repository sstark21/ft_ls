/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_from.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 13:00:22 by sstark            #+#    #+#             */
/*   Updated: 2019/02/09 15:38:06 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_del_from(t_list **alst, t_list *lst, void (*del)(void *, size_t))
{
	t_list *lst1;

	lst1 = *alst;
	while (lst1)
	{
		if (lst1->next == lst)
		{
			lst1->next = lst->next;
			if (lst->content != NULL)
				del(lst->content, lst->content_size);
			free(lst);
			return ;
		}
		else if (lst1 == lst)
		{
			*alst = lst->next;
			if (lst->content != NULL)
				del(lst->content, lst->content_size);
			free(lst);
			return ;
		}
		lst1 = lst1->next;
	}
}
