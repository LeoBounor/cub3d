/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:59:29 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/11 17:40:29 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len_dst;

	len_dst = ft_strlen(dst);
	if (dstsize == 0 || len_dst >= dstsize)
		return (dstsize + ft_strlen(src));
	while (*dst)
	{
		dst++;
		dstsize--;
	}
	i = 0;
	while (dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = 0;
	return (ft_strlen(src) + len_dst);
}
