/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:56:43 by Leo               #+#    #+#             */
/*   Updated: 2023/06/15 13:35:47 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	stop_mlx(t_game *game)
{
	if (ON_LINUX)
		game->x = 1;
}

void	ft_err_map(char *str, void *ptr, t_game *game)
{
	int		i;
	size_t	res;

	if (ptr != NULL)
		free(ptr);
	stop_mlx(game);
	i = 0;
	if (write(2, "Error\n", 6) != -1 && !str)
		exit(EXIT_FAILURE);
	while (str[i])
	{
		res = write(2, &str[i], 1);
		if (res == 0)
			break ;
		i++;
	}
	exit(EXIT_FAILURE);
}

void	read_error(int fd, char *buffer, char *str, t_game *game)
{
	close(fd);
	ft_err_map(str, buffer, game);
}

char	*ft_read_all(int fd, t_game *game, int i)
{
	char	*all;
	char	*buffer;

	if (fd == -1)
		ft_err_map("Can't open this file\n", NULL, game);
	all = NULL;
	buffer = malloc(sizeof(char) * (17));
	if (!buffer)
		return (NULL);
	while (i != 0)
	{
		i = read(fd, buffer, 16);
		if (i == -1)
			read_error(fd, buffer, "Error while reading the file\n", game);
		buffer[i] = '\0';
		all = ft_free_strjoin(all, buffer);
		if (!all && clear_textures(game))
			read_error(fd, buffer, "Error while reading the file\n", game);
	}
	free(buffer);
	if (all[ft_strlen(all) - 1] != '\n')
		return (ft_free_strjoin(all, "\n"));
	return (all);
}
