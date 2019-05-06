/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:28:50 by sstark            #+#    #+#             */
/*   Updated: 2019/01/21 16:57:21 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	char	*str;
	char	*to_find;

	str = (char *)haystack;
	to_find = (char *)needle;
	i = 0;
	while (*to_find && *str)
	{
		if (*str == *to_find)
		{
			to_find++;
			i++;
		}
		else
		{
			to_find -= i;
			str -= i;
			i = 0;
		}
		str++;
	}
	if (*to_find != '\0')
		return (NULL);
	return (str - i);
}
