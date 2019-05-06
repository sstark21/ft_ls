/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 20:53:43 by sstark            #+#    #+#             */
/*   Updated: 2019/02/06 16:45:00 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static	char	*ft_movecpy(char const **s, char c)
{
	char	*rez;
	int		i;

	i = ft_strnlen(*s, c);
	rez = ft_strnew(i);
	if (!rez)
		return (NULL);
	while (**s != c && **s)
	{
		*rez++ = **s;
		(*s)++;
	}
	return (rez - i);
}

static	char	**ft_check(char **s, int f)
{
	int		j;
	int		flag;

	flag = 0;
	j = f;
	if (!s)
		return (NULL);
	while (j > 0)
	{
		if (!s[j-- - 1])
			flag = 1;
	}
	if (flag)
	{
		while (f > -1)
			ft_memdel((void *)&s[f--]);
		free(s);
	}
	return (flag ? NULL : s);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**rez;

	if (!s)
		return (NULL);
	i = ft_wordnbr((char *)s, c);
	if (!(rez = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	rez[i] = NULL;
	while (*s && rez)
	{
		if (*s != c)
			*rez++ = ft_movecpy(&s, c);
		else
			s++;
	}
	return (ft_check(rez - i, i));
}
