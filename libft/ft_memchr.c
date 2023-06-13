/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:53:17 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/09 16:35:44 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*strtmp;

	strtmp = (unsigned char *)str;
	i = 0;
	while (n > 0)
	{
		if (strtmp[i] == (unsigned char)c)
			return (&strtmp[i]);
		n--;
		i++;
	}
	return (0);
}
