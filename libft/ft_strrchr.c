/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:56:44 by sstark            #+#    #+#             */
/*   Updated: 2019/01/21 16:57:21 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *last_chr;

	last_chr = NULL;
	while (*str)
	{
		if (*str == (char)ch)
			last_chr = (char *)str;
		str++;
	}
	if (*str == (char)ch)
		return ((char *)str);
	else
		return (last_chr);
}
