/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 22:18:42 by sstark            #+#    #+#             */
/*   Updated: 2019/01/13 14:46:19 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t hlen)
{
	size_t	i;
	size_t	j;
	size_t	lenn;
	size_t	lenh;

	lenn = ft_strlen((char *)needle);
	lenh = ft_strlen((char *)haystack);
	if (*needle == '\0')
		return ((char *)haystack);
	if (lenn > hlen || lenn > lenh)
		return (NULL);
	i = 0;
	while (i <= (hlen - lenn) && i < lenh)
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
