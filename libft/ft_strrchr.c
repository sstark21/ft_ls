/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:34 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:40:35 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*n;

	n = (char *)s + ft_strlen(s);
	if ((char)c == '\0')
		return (n);
	while (n >= s)
	{
		if (*n == (char)c)
			return (n);
		n--;
	}
	return (NULL);
}
