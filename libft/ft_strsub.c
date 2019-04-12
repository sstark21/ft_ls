/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:52 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:40:53 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*frs;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (NULL);
	if (!(frs = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		frs[i] = s[start];
		i++;
		start++;
	}
	frs[i] = '\0';
	return (frs);
}
