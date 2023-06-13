/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:57:18 by vducoulo          #+#    #+#             */
/*   Updated: 2022/05/11 16:02:00 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_putstr_fd(char *str, int fd)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (str)
	{
		while (str[i])
		{
			res += ft_putchar_fd(str[i++], fd);
		}
	}
	else
		res += ft_putstr_fd("(null)", 1);
	return (res);
}
