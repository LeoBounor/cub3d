/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:32:45 by Leo               #+#    #+#             */
/*   Updated: 2021/11/10 15:36:59 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nblen(long long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n >= 0)
	{
		n = n / 10;
		len++;
		if (n == 0)
			break ;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*strconvert;
	long long int	long_n;

	long_n = n;
	len = ft_nblen(long_n);
	i = 0;
	strconvert = (char *)malloc(sizeof(char) * len + 1);
	if (!strconvert)
		return (NULL);
	strconvert[len--] = '\0';
	if (n == 0)
		strconvert[0] = '0';
	if (n < 0)
	{
		long_n = long_n * -1;
		strconvert[0] = '-';
	}
	while (long_n > 0)
	{
		strconvert[len--] = 48 + (long_n % 10);
		long_n = long_n / 10;
	}
	return (strconvert);
}
