/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:49:03 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/15 13:27:19 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict_dst, const char *restrict_src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && restrict_src[i])
		{
			restrict_dst[i] = restrict_src[i];
			i++;
		}
	restrict_dst[i] = '\0';
	}
	return (ft_strlen(restrict_src));
}
