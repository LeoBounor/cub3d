/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:59:47 by jcollon           #+#    #+#             */
/*   Updated: 2023/02/03 16:43:25 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t limit)
{
	int	i;

	if (*needle == 0)
		return ((char *) haystack);
	while (limit && *haystack)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (limit - i && haystack[i] == needle[i]
				&& haystack[i] && needle[i])
				i++;
			if (i == ft_strlen(needle))
				return ((char *) haystack);
		}
		haystack++;
		limit--;
	}
	return (0);
}
