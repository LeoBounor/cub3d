/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:08:14 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/25 23:38:50 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	givemelen(unsigned int nb)
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

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	r;
	size_t			len;

	r = n;
	len = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		r = -n;
		len++;
	}
	else
		r = n;
	len += givemelen(r);
	if (r / 10)
	{
		ft_putnbr_fd(r / 10, fd);
		ft_putchar_fd(r % 10 + '0', fd);
	}
	else
		ft_putchar_fd(r % 10 + '0', fd);
	return (len);
}
