/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:29:55 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/10 15:54:53 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			len_needle;
	unsigned char	*h;
	unsigned char	*n;

	i = 0;
	h = (unsigned char *)haystack;
	n = (unsigned char *)needle;
	len_needle = ft_strlen((char *)n);
	if (n[0] == '\0')
		return ((char *)h);
	while (h[i] && i + len_needle <= len)
	{
		if (h[i] == n[0])
		{
			if (ft_strncmp((char *)&h[i], (char *)n, len_needle) == 0)
				return ((char *)&h[i]);
		}
		i++;
	}
	return (0);
}
