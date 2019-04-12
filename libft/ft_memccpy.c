/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:37:14 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:37:15 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		j;
	const char	*str1;
	char		*str2;

	j = 0;
	str1 = src;
	str2 = dest;
	while (j < n)
	{
		str2[j] = str1[j];
		if (str2[j] == (char)c)
			return (str2 + j + 1);
		j++;
	}
	return (NULL);
}
