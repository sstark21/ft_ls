/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 17:23:03 by sstark            #+#    #+#             */
/*   Updated: 2018/12/30 17:23:06 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_itoa(int n)
{
	long int	len;
	int			i;
	char		*new;
	int			sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n < 0 ? 1 : 0;
	i = 1;
	len = n < 0 ? -n : n;
	while (n /= 10)
		i++;
	if (!(new = (char *)malloc(i + sign + 1)))
		return (new);
	if (sign)
		*new++ = '-';
	new[i] = '\0';
	if (len == 0)
		return (ft_strcpy(new, "0"));
	while (i--)
	{
		new[i] = (len % 10 + '0');
		len /= 10;
	}
	return (new - sign);
}
