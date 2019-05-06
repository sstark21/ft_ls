/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:55:54 by sstark            #+#    #+#             */
/*   Updated: 2018/12/17 15:55:56 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const	void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	unsigned int	i;

	if (s1 == s2)
		return (0);
	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (n > i)
		if (c1[i] == c2[i])
			i++;
		else
			break ;
	if (n == i)
		return (0);
	return (c1[i] - c2[i]);
}
