/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:45 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:40:46 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *strb, const char *stra)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = 0;
	while (stra[l] != '\0')
		l++;
	if (*stra == '\0')
		return ((char *)strb);
	while (strb[i] != '\0')
	{
		while (stra[j] == strb[i + j])
		{
			if (j == l - 1)
				return ((char *)strb + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
