/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:21:23 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 23:52:13 by Leo              ###   ########lyon.fr   */
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
