/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 00:14:44 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/17 18:18:03 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	givemedatlen(int i)
{
	int		len;

	len = 0;
	while (i / 10)
	{
		i = i / 10;
		len ++;
	}
	len ++;
	return (len);
}

static char	*givemedatdest(int sign, char *dest, unsigned int r, int len)
{
	if (sign < 0)
		dest[0] = '-';
	dest[len] = '\0';
	while (len > 0 && dest[len - 1] != '-')
	{
		dest[len - 1] = r % 10 + '0';
		r = r / 10;
		len --;
	}
	return (dest);
}

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	r;
	char			*dest;
	int				sign;

	len = givemedatlen(n);
	sign = 1;
	if (n < 0)
	{
		r = -n;
		len += 1;
		sign = -1;
	}
	else
		r = n;
	dest = malloc(len * sizeof(char) + 1);
	if (dest)
	{
		return (givemedatdest(sign, dest, r, len));
	}
	else
		return (NULL);
}
