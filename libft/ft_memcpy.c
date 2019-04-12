/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:37:32 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:37:33 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	s1 = ((char*)dest);
	s2 = ((char*)src);
	while (n--)
		*s1++ = *s2++;
	return (dest);
}
