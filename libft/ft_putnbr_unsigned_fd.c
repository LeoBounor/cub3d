/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:23:26 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/25 23:38:21 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	givemeunlen(unsigned int nb)
{
	int	res;

	res = 0;
	while (nb / 10)
	{
		res++;
		nb = nb / 10;
	}
	return (res + 1);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	unsigned int	r;

	r = n;
	if (r / 10)
	{
		ft_putnbr_unsigned_fd(r / 10, fd);
		ft_putchar_fd(r % 10 + '0', fd);
	}
	else
		ft_putchar_fd(r % 10 + '0', fd);
	return (givemeunlen(n));
}
