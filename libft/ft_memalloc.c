/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 13:47:18 by sstark            #+#    #+#             */
/*   Updated: 2018/12/25 13:47:20 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_memalloc(size_t size)
{
	char		*area;
	char		*cp;

	area = (char*)malloc(size);
	if (area == NULL)
		return (NULL);
	cp = area;
	while (size--)
		*cp++ = (char)0;
	return ((void*)area);
}
