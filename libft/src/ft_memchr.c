/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:19:47 by jcollon           #+#    #+#             */
/*   Updated: 2023/01/31 19:42:59 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t limit)
{
	while (limit && *(char *) str)
	{
		if (*(char *) str == (char) c)
			return ((void *) str);
		limit--;
		str++;
	}
	return (0);
}
