/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:36:02 by jcollon           #+#    #+#             */
/*   Updated: 2022/05/17 23:40:43 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isincharset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

int	len_start(const char *s1, const char *set)
{
	int	len;

	len = 0;
	while (s1[len] && isincharset(s1[len], set))
		len++;
	return (len);
}

int	len_end(const char *s1, const char *set)
{
	int	len;
	int	len_s1;

	len = 0;
	len_s1 = ft_strlen(s1);
	while (s1[len_s1 - len - 1] && isincharset(s1[len_s1 - len - 1], set))
		len++;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (0);
	start = len_start(s1, set);
	if (start != ft_strlen(s1))
		end = len_end(s1 + start, set);
	else
		end = 0;
	ret = malloc((ft_strlen(s1 + start) - end + 1) * sizeof(*ret));
	if (!ret)
		return (0);
	i = -1;
	while (++i < ft_strlen(s1) - start - end)
		ret[i] = s1[start + i];
	ret[i] = 0;
	return (ret);
}
