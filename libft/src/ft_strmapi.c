/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:23:53 by jcollon           #+#    #+#             */
/*   Updated: 2023/02/03 16:54:28 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (!str || !f)
		return (0);
	i = 0;
	ret = malloc((ft_strlen((char *) str) + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	while (str[i])
	{
		ret[i] = f(i, str[i]);
		i++;
	}
	ret[i] = 0;
	return (ret);
}
