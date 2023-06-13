/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:10:14 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/17 15:42:53 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			i;
	size_t			o;
	char			*dest;

	if (!s1 || !set)
		return (NULL);
	o = ft_strlen(s1);
	i = 0;
	while (i < o && ft_strchr(set, s1[i]))
	{
		i++;
	}
	while (ft_strchr(set, s1[o]) && o > 0)
		o--;
	if (o >= i)
	{
		dest = malloc((o - i + 2) * sizeof(char));
		if (!dest)
		{
			return (NULL);
		}
		ft_strlcpy(dest, &s1[i], o - i + 2);
		return (dest);
	}
	return (ft_calloc(sizeof(char), 1));
}
