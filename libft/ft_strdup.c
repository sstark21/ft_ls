/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <sstark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:39:17 by gorange-          #+#    #+#             */
/*   Updated: 2019/04/04 19:40:16 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tmp;
	long	len;
	long	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	tmp = (char*)malloc(len + 1);
	if (!tmp)
		return (NULL);
	i = len;
	len = 0;
	while (len < i)
	{
		tmp[len] = src[len];
		len++;
	}
	tmp[len] = '\0';
	return (tmp);
}
