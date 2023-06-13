/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:36:54 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/09 16:53:33 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1tmp;
	unsigned char	*s2tmp;

	s1tmp = (unsigned char *)s1;
	s2tmp = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1tmp[i] == (unsigned char)s2tmp[i])
			i++;
		else
			return ((unsigned char)s1tmp[i] - (unsigned char)s2tmp[i]);
	}
	return (0);
}
