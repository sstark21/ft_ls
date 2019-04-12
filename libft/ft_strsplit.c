/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:40:39 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:40:40 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		free_all(char ***arr)
{
	char	**ptr;

	if (!arr)
		return ;
	ptr = *arr;
	while (ptr++)
		free(ptr);
	free(*arr);
	*arr = NULL;
}

static char		**add_words(char **fstr, int l, const char *s, char c)
{
	int		i;
	int		j;
	int		bg;

	i = 0;
	j = -1;
	while (++j < l)
	{
		while (s[i] && s[i] == c)
			i++;
		bg = i;
		while (s[i] && s[i] != c)
			i++;
		if (!(fstr[j] = ft_strsub(s, bg, i - bg)))
		{
			free_all(&fstr);
			return (NULL);
		}
		i++;
	}
	fstr[j] = NULL;
	return (fstr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		l;
	char	**fstr;

	l = ft_count(s, c);
	if ((c == 0) || (s == 0))
		return (NULL);
	if (!(fstr = malloc((sizeof(char *) * (l + 1)))))
		return (NULL);
	if (!(fstr = add_words(fstr, l, s, c)))
		return (NULL);
	return (fstr);
}
