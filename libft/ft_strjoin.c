/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:54:34 by vducoulo          #+#    #+#             */
/*   Updated: 2022/06/15 17:45:26 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	s1len = (size_t)ft_strlen(s1);
	s2len = (size_t)ft_strlen(s2);
	dest = malloc((s1len + s2len) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while ((char)s1[i++])
		dest[i - 1] = (char)s1[i - 1];
	i--;
	while ((char)s2[i - s1len])
	{
		dest[i] = (char)s2[i - s1len];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
