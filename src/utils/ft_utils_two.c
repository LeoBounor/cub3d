/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:19:05 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 01:05:33 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	skip_to_next_word(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\r')
			break ;
		*i += 1;
	}
}

void	skip_to_eol_or_eof(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\n' || str[*i] == '\0')
			break ;
		*i += 1;
	}
}

void	skip_to_next_parse(t_game *game, int *i)
{
	while (game->fd_str[*i])
	{
		skip_to_next_word(game->fd_str, i);
		if (game->fd_str[*i] != '\n')
			break ;
		(*i)++;
	}
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	len = 0;
	if (s2)
		while (s2[len])
			res[i++] = s2[len++];
	res[i] = 0;
	free(s1);
	return (res);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len + 1);
}
