/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 21:40:03 by sstark            #+#    #+#             */
/*   Updated: 2018/12/30 21:40:09 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	ft_memcpy(dst, src, n);
	i = ft_strlen((char *)dst);
	while (n > i)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
