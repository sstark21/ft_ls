/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:59 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:41:00 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!s[0])
		return (ft_strnew(0));
	i = 0;
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[j] == ' ' || s[j] == '\n' ||
	s[j] == '\t' || s[j] == '\0') && j > i)
		j--;
	j++;
	if (!(str = (char*)ft_strnew(j - i)))
		return (NULL);
	ft_strncpy(str, s + i, j - i);
	return (str);
}
