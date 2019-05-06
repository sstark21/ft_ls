/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponentiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:48:15 by sstark            #+#    #+#             */
/*   Updated: 2018/12/18 11:48:17 by sstark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_exponentiation(int dig, int exp)
{
	int c;

	c = dig;
	if (exp == 0)
		return (1);
	while (--exp > 0)
	{
		c *= dig;
	}
	return (c);
}
