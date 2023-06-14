/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:22:40 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/10 13:13:13 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*b;
	unsigned char	ch;
	size_t			i;

	i = 0;
	b = (unsigned char *)str;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (b[i] == ch)
			return (&b[i]);
		i++;
	}
	return (NULL);
}
