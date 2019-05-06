/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:38:15 by sstark            #+#    #+#             */
/*   Updated: 2018/12/17 19:38:17 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;
	int		c;

	c = ft_strlen((char *)(s1));
	i = 0;
	p = (char *)malloc((c + 1) * sizeof(char));
	if (p)
	{
		while (i <= c)
		{
			p[i] = s1[i];
			i++;
		}
	}
	return (p);
}
