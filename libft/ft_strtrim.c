/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:17:49 by sstark            #+#    #+#             */
/*   Updated: 2018/12/26 21:17:52 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	void	help(size_t *begin, size_t *end, char const *s)
{
	size_t		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	*begin = i;
	*end = i + 1;
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			*end = i + 1;
		i++;
	}
}

char			*ft_strtrim(char const *s)
{
	size_t		begin;
	size_t		end;
	size_t		alloc;
	char		*dst;

	if (s == NULL)
		return (NULL);
	help(&begin, &end, s);
	alloc = end - begin + 1;
	dst = (char*)malloc(alloc);
	if (!dst)
		return (NULL);
	ft_strncpy(dst, &s[begin], end - begin);
	dst[end - begin] = '\0';
	return (dst);
}
