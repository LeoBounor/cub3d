/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:27:05 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/10 04:42:02 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned long int	i;
	char				*ret;

	i = 0;
	ret = malloc(count * size);
	if (!ret)
		return (0);
	while (i < count * size)
		ret[i++] = 0;
	return (ret);
}
