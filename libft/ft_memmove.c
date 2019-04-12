/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:37:42 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:37:43 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	if (src == dest || n == 0)
		return (dest);
	str1 = (char *)src;
	str2 = (char *)dest;
	if (str1 < str2 || str2 >= (str1 + n))
	{
		i = n;
		while (i-- > 0)
			str2[i] = str1[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			str2[i] = str1[i];
			i++;
		}
	}
	return (dest);
}
