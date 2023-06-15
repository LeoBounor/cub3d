/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:07:07 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 11:22:27 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	get_dimension(int *h, int *w, char *str)
{
	int	i;
	int	biggest;

	*h = 0;
	*w = 0;
	biggest = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (*w < biggest)
				*w = biggest;
			biggest = 0;
			*h += 1;
			i++;
		}
		biggest++;
		if (str[i])
			i++;
	}
}

/*
**	On remplit un tableau d'entiers avec les valeurs de notre map
**	contenu dans un tableau de charactères.
**	Les espaces vide sont remplacés par 2.
*/
int	*fill_tab(t_game *game, char *line, int i, int j)
{
	int			*str;
	t_parsing	p;

	p.x = 0;
	p.y = i;
	str = ft_calloc(game->game_tab_width, sizeof(int));
	while (i != 0)
		if (line[p.x++] == '\n')
			i--;
	while (line[p.x] && line[p.x] != '\n')
	{
		if (line[p.x] != 48 && line[p.x] != 49 && line[p.x] != 78 && line[p.x] \
		!= 83 && line[p.x] != 69 && line[p.x] != 87 && line[p.x] != 32 && \
		clear_textures(game) && free_map(game->game_tab, p.y))
			return (ft_err_map("Invalid map char\n", game->fd_str, game), NULL);
		if (line[p.x] == ' ')
			str[j] = 2;
		else
			str[j] = line[p.x] - '0';
		j++;
		p.x++;
	}
	while (j != game->game_tab_width)
		str[j++] = 2;
	return (str);
}

void	check_all_before_gen_map(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '1' && str[i] != '0' \
		&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E' \
		&& clear_textures(game))
			ft_err_map("Invalid char in the map\n", game->fd_str, game);
		i++;
	}
	if (game->all_textures->east_texture->texture && \
	game->all_textures->west_texture->texture && \
	game->all_textures->north_texture->texture && \
	game->all_textures->south_texture->texture && \
	game->floor_color[0] != -1 && game->ceiling_color[0] != -1)
		return ;
	clear_textures(game);
	ft_err_map("At least one texture or color is missing\n", game->fd_str, game);
}

void	generate_tab(t_game *game, char *line)
{
	int		i;

	check_all_before_gen_map(game, line);
	i = 0;
	while (*(line - 1) != '\n')
		line--;
	get_dimension(&game->game_tab_height, &game->game_tab_width, line);
	game->game_tab = malloc(sizeof(int *) * game->game_tab_height);
	if (!game->game_tab && clear_textures(game))
		ft_err_map("Malloc error\n", game->fd_str, game);
	while (i != game->game_tab_height)
	{
		game->game_tab[i] = fill_tab(game, line, i, 0);
		i++;
	}
	if ((game->game_tab_height < 3 || game->game_tab_width < 3) && \
		clear_textures(game))
	{
		free_map(game->game_tab, game->game_tab_height - 1);
		ft_err_map("Map too small\n", game->fd_str, game);
	}
	check_map(game, 1, 1);
}
