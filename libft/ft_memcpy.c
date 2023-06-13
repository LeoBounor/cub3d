/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:37:56 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/15 13:29:25 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *restrict_dst, const void *restrict_src, size_t n)
{
	char		*dsttmp;
	const char	*srctmp;

	dsttmp = restrict_dst;
	srctmp = restrict_src;
	if (!dsttmp && !srctmp)
		return (NULL);
	while (n-- > 0)
		*dsttmp++ = *srctmp++;
	return (restrict_dst);
}
