/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:05:02 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/10 13:13:13 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = ft_strlen(dst);
	if (dstsize < count || dstsize == 0)
		return (ft_strlen((char *)src) + dstsize);
	while (src[i] != '\0' && i + count < dstsize - 1)
	{
		dst[i + count] = src[i];
		i++;
	}
	dst[i + count] = '\0';
	return (count + ft_strlen((char *)src));
}
