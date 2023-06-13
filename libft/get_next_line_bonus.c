/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:31:55 by vducoulo          #+#    #+#             */
/*   Updated: 2022/01/12 20:37:13 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findfirst(char *buf, char c)
{
	int	i;

	if (buf)
	{
		i = 0;
		while (buf[i])
		{
			if (buf[i] == c)
				return (i + 1);
			i++;
		}
	}
	return (0);
}

void	readall(int fd, char **hay)
{
	int			justread;
	char		buf[BUFFER_SIZE + 1];

	justread = 1;
	while ((!ft_findfirst(hay[fd], '\n') || hay[fd] == NULL) && justread)
	{
		justread = read(fd, buf, BUFFER_SIZE);
		if (justread == -1 || justread == 0)
			return ;
		buf[justread] = '\0';
		hay[fd] = ft_strjoinb2(hay[fd], buf);
	}
}

char	*get_next_line(int fd)
{
	static char	*hay[1024 + 1];
	char		*tosend;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	readall(fd, &*hay);
	if (!hay[fd])
		return (NULL);
	tosend = ft_substr(hay[fd], 0, ft_findfirst(hay[fd], '\n'));
	if (!ft_strlenprotect(tosend))
	{
		free(tosend);
		tosend = ft_substr(hay[fd], 0, ft_strlenprotect(hay[fd]));
		free(hay[fd]);
		hay[fd] = NULL;
	}
	hay[fd] = ft_strchrb2(hay[fd], '\n');
	if (!ft_strlenprotect(tosend))
	{
		free(tosend);
		tosend = NULL;
	}
	return (tosend);
}
