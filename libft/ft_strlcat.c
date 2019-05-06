/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:50:23 by sstark            #+#    #+#             */
/*   Updated: 2019/01/20 19:50:02 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	int		i;
	size_t	help;
	size_t	len_src;

	i = 0;
	help = ft_strlen(dst);
	len_dst = ft_strlen(dst);
	len_src = ft_strlen((char *)src);
	if (size < len_dst + 1)
		return (len_src + size);
	if (size > len_dst + 1)
	{
		while (help < size - 1 && src[i])
			*(dst + help++) = *(src + i++);
		*(dst + help) = '\0';
	}
	return (len_dst + len_src);
}
