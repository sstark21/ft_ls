/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:29 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:40:30 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (*str2 == '\0')
		return ((char *)str1);
	i = ft_strlen(str2);
	while (*str1 && n >= i)
	{
		if (*str1 == *str2 && ft_memcmp(str1, str2, i) == 0)
			return ((char *)str1);
		str1++;
		n--;
	}
	return (NULL);
}
