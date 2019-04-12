/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:37:20 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:37:21 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t count)
{
	size_t	i;
	char	c1;
	char	*c2;

	i = 0;
	c2 = (char*)buf;
	c1 = (char)ch;
	while (i < count)
	{
		if (c2[i] == c1)
			return (&c2[i]);
		i++;
	}
	return (NULL);
}
