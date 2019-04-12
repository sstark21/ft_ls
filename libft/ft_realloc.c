/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorange- <gorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:38:40 by gorange-          #+#    #+#             */
/*   Updated: 2019/01/06 15:38:41 by gorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *str, size_t s)
{
	char	*fstr;

	if (str == NULL)
		return (malloc(s));
	if (s <= sizeof(str))
		return (str);
	fstr = malloc(s);
	ft_memcpy(str, fstr, sizeof(s));
	free(str);
	return (fstr);
}
