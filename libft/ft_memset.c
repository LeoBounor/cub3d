/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:38:00 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/15 14:25:41 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*z;
	size_t			i;

	i = 0;
	z = (unsigned char *)b;
	while (i < len)
	{
		z[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
