/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:18:13 by jcollon           #+#    #+#             */
/*   Updated: 2023/01/31 19:18:30 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *ptr, size_t size)
{
	char	*str;

	str = ptr;
	while (size)
	{
		*str = 0;
		str++;
		size--;
	}
}
