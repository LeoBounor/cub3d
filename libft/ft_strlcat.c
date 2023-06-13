/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:53:35 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/13 11:20:56 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	o;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	o = ft_strlen(dst);
	if (dstsize > (size_t)ft_strlen(dst))
	{
		while (dstsize > 0 && i < dstsize - o + i - 1 && src[i])
			dst[o++] = src[i++];
		dst[o] = '\0';
		while (src[i++])
			o++;
		return (o);
	}
	else
		return (srclen + dstsize);
}
