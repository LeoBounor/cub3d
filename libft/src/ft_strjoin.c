/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:00:42 by jcollon           #+#    #+#             */
/*   Updated: 2021/11/11 17:50:18 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ret;
	unsigned int	len;
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen((char *) s1) + ft_strlen((char *) s2);
	i = 0;
	ret = malloc((len + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	while (len--)
	{
		if (*s1)
		{
			ret[i] = *s1;
			s1++;
		}
		else
			ret[i] = *(s2++);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
