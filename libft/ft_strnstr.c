/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:00:56 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/08 16:43:58 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	o;

	if (!tofind[0])
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		o = 0;
		while (str[i + o] == tofind[o] && i + o < len)
		{
			if (tofind[o + 1] == '\0')
				return ((char *)&str[i]);
			o++;
		}
		i++;
	}
	return (0);
}
