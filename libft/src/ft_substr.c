/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:54:34 by jcollon           #+#    #+#             */
/*   Updated: 2023/02/03 17:01:07 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t limit)
{
	char			*ret;
	unsigned int	i;
	size_t			len_malloc;

	if (!str)
		return (0);
	if (start >= (unsigned int) ft_strlen(str))
		return (ft_strdup(""));
	len_malloc = ft_strlen(str + start);
	if (len_malloc >= limit)
		len_malloc = limit;
	ret = malloc((len_malloc + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	i = 0;
	while (limit && str[start + i])
	{
		ret[i] = str[start + i];
		i++;
		limit--;
	}
	ret[i] = 0;
	return (ret);
}
