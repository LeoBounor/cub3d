/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:00:45 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 23:36:08 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
