/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base_printf_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:40:52 by vducoulo          #+#    #+#             */
/*   Updated: 2023/06/13 23:30:36 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	givemedatcount(unsigned long nb, int baselen, char towork)
{
	int	count;

	count = 0;
	if (towork == 'p')
		count = 2;
	while (nb / baselen)
	{
		nb = nb / baselen;
		count++;
	}
	return (count + 1);
}

int	ft_convert_base_printf_fd(unsigned long nb, char towork, int fd)
{
	int		baselen;
	int		outlen;
	char	*base;

	if (towork >= 'A' && towork <= 'Z')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	baselen = ft_strlen(base);
	outlen = givemedatcount(nb, baselen, towork);
	if (towork == 'p')
	{
		ft_putstr_fd("0x", 1);
		towork = 'o';
	}
	if (nb / baselen)
		ft_convert_base_printf_fd(nb / baselen, towork, fd);
	ft_putchar_fd(base[nb % baselen], fd);
	return (outlen);
}
