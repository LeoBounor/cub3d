/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:30:57 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/15 15:20:59 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	sizeint(long int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		ret++;
	}
	ret++;
	return (ret);
}

char	*ft_itoa(int n)
{
	char			*ret;
	unsigned int	len;
	long int		nb;

	nb = n;
	len = sizeint(nb);
	ret = malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	ret[len] = 0;
	len--;
	if (nb < 0)
	{
		nb = -nb;
		ret[0] = '-';
	}
	while (nb > 9)
	{
		ret[len] = nb % 10 + 48;
		len--;
		nb /= 10;
	}
	ret[len] = nb % 10 + 48;
	return (ret);
}
