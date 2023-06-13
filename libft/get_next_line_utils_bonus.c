/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:45:20 by vducoulo          #+#    #+#             */
/*   Updated: 2022/01/12 20:56:43 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenprotect(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoinb2(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	char	*dest;

	if (!s1 && !s2)
		return (NULL);
	s1len = (size_t)ft_strlenprotect(s1);
	s2len = (size_t)ft_strlenprotect(s2);
	dest = malloc((s1len + s2len) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1 != NULL && (char)s1[i++])
		dest[i - 1] = (char)s1[i - 1];
	if (s1)
		i--;
	while ((char)s2[i - s1len])
	{
		dest[i] = (char)s2[i - s1len];
		i++;
	}
	dest[i] = '\0';
	free((void *)s1);
	return (dest);
}

char	*ft_strchrb2(const char *str, int c)
{
	size_t	i;
	size_t	o;
	char	*realdest;

	i = 0;
	o = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char) c)
		{
			realdest = malloc(ft_strlenprotect((char *)&str[i]) + 1);
			while (str[i + o])
			{
				realdest[o] = str[i + o + 1];
				o++;
			}
			realdest[o] = '\0';
			free((void *)str);
			return (realdest);
		}
		i++;
	}
	return (NULL);
}
