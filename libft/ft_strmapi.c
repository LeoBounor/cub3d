/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:11:37 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/17 15:11:27 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (dest)
	{
		while (s[i])
		{
			dest[i] = f(i, s[i]);
			i ++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (0);
}
