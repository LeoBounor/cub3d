/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:47:56 by lbounor           #+#    #+#             */
/*   Updated: 2021/11/10 13:13:13 by lbounor          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int		lenght;

	lenght = 0;
	while (src[lenght] != '\0')
	{
		dest[lenght] = src[lenght];
		lenght++;
	}
	dest[lenght] = src[lenght];
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = malloc((ft_strlen((char *)s1) + 1) * sizeof(*dup));
	if (dup == 0)
		return (0);
	ft_strcpy(dup, (char *)s1);
	return (dup);
}
