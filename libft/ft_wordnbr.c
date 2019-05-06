/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:06:48 by sstark            #+#    #+#             */
/*   Updated: 2019/01/17 17:06:50 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_wordnbr(char *str, char c)
{
	int		i;

	i = (*str != c && *str);
	while (*str)
	{
		if (*str == c)
		{
			while (*str == c && *str)
				str++;
			if (*str)
				i++;
		}
		if (*str)
			str++;
	}
	return (i);
}
