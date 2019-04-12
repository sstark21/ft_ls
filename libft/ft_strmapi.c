/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:39:57 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:39:58 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*frs;

	i = 0;
	if (!s || !f)
		return (NULL);
	frs = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (frs == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		frs[i] = (*f)(i, (char)s[i]);
		i++;
	}
	frs[i] = '\0';
	return (frs);
}
