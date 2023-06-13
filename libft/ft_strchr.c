/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:51:56 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/08 23:50:12 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str[0] == (char) c)
		return ((char *)&str[0]);
	while (str[i++])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
	}
	return (0);
}
