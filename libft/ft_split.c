/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:23:52 by vducoulo          #+#    #+#             */
/*   Updated: 2021/11/17 17:57:52 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ocounter(char const *s, int i, char c)
{
	size_t	o;

	o = 0;
	while (s[i + o] && s[i + o] != c)
	{
		o++;
	}
	return (o);
}

static int	givemedatcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (ocounter(s, i, c) > 0)
		{
			count++;
			i += ocounter(s, i, c);
		}
		else
			i++;
	}
	return (count);
}

static char	*givemedatsplit(char const *s, int i, char c, char **dest)
{
	int		ocount;
	size_t	o;
	char	*str;

	o = 0;
	ocount = ocounter(s, i, c);
	str = ft_substr(s, i, ocount);
	if (!str)
	{
		while (dest[o])
			free(dest[o++]);
		free(dest);
		return (0);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	o;
	char	**dest;

	if (!s)
		return (NULL);
	dest = malloc((givemedatcount(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	o = 0;
	while (s[i])
	{
		if (ocounter(s, i, c) > 0)
		{
			dest[o++] = givemedatsplit(s, i, c, dest);
			if (!dest[o - 1])
				return (NULL);
			i += ocounter(s, i, c);
		}
		else
			i++;
	}
	dest[o] = NULL;
	return (dest);
}
