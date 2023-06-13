/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:06:31 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/16 13:22:41 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	destlen;
	char	*dest;

	if (!s)
		return (0);
	destlen = 0;
	if (start <= (unsigned int)ft_strlen(s))
		destlen = ft_strlen(s + start);
	else
		return (ft_memset(malloc(1), '\0', 1));
	if (len < destlen)
		destlen = len;
	i = start;
	dest = malloc(destlen * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (i - start < destlen && s[i])
	{
		dest[i - start] = (char)s[i];
		i++;
	}
	dest[i - start] = '\0';
	return (dest);
}
