/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:28:58 by jcollon           #+#    #+#             */
/*   Updated: 2023/01/31 19:45:24 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t limit)
{
	unsigned int	i;
	const char		*str1;
	const char		*str2;

	i = 0;
	str1 = s1;
	str2 = s2;
	if (limit == 0)
		return (0);
	while (str1[i] == str2[i] && i < limit - 1 && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}
