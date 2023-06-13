/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:20:54 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/09 18:00:33 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	i;
	size_t	len;

	len = ft_strlen((char *)s1);
	tmp = (char *)malloc(len * sizeof(char) + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = (char)s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
