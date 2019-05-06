/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:01:26 by sstark            #+#    #+#             */
/*   Updated: 2019/01/21 16:57:21 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dst;
	ps = (unsigned char *)src;
	if (dst > src)
	{
		pd += len - 1;
		ps += len - 1;
		while (len--)
			*pd-- = *ps--;
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)(dst));
}
