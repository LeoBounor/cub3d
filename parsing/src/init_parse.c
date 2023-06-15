/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:50:18 by Leo               #+#    #+#             */
/*   Updated: 2023/06/15 14:10:24 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	define_typeof_struct(char *str, int i, int *type)
{
	skip_to_next_word(str, &i);
	while (str[i] == '\n')
	{
		i++;
		skip_to_next_word(str, &i);
	}
	skip_to_next_word(str, &i);
	if (!ft_strncmp(str + i, "NO ", 3) || !ft_strncmp(str + i, "NO	", 3))
		*type = 1;
	else if (!ft_strncmp(str + i, "SO ", 3) || !ft_strncmp(str + i, "SO	", 3))
		*type = 2;
	else if (!ft_strncmp(str + i, "WE ", 3) || !ft_strncmp(str + i, "WE	", 3))
		*type = 3;
	else if (!ft_strncmp(str + i, "EA ", 3) || !ft_strncmp(str + i, "EA	", 3))
		*type = 4;
	else if (!ft_strncmp(str + i, "F ", 2) || !ft_strncmp(str + i, "F	", 3))
		*type = 5;
	else if (!ft_strncmp(str + i, "C ", 2) || !ft_strncmp(str + i, "C	", 3))
		*type = 6;
	else if (!ft_strncmp(str + i, "1", 1))
		*type = 7;
	else
		*type = 0;
}

/*
	TYPE 1 = NORTH
	TYPE 2 = SOUTH
	TYPE 3 = WEST
	TYPE 4 = EAST
	TYPE 5 = FLOOR COLOR
	TYPE 6 = CEILING COLOR
	TYPE 7 = BEGINNING OF MAP
	TYPE 0 = INVALID INPUTE
*/
void	sort_parse(t_game *game, int type, int i)
{
	while (game->fd_str[i])
	{
		skip_to_next_parse(game, &i);
		define_typeof_struct(game->fd_str, i, &type);
		if (type == 1)
			load_texture(game, game->all_textures->north_texture, &i);
		else if (type == 2)
			load_texture(game, game->all_textures->south_texture, &i);
		else if (type == 3)
			load_texture(game, game->all_textures->west_texture, &i);
		else if (type == 4)
			load_texture(game, game->all_textures->east_texture, &i);
		else if (type == 5)
			load_color(game, &game->floor_color, &i, 0);
		else if (type == 6)
			load_color(game, &game->ceiling_color, &i, 0);
		else if (type == 7)
			return (generate_tab(game, (game->fd_str + i)));
		else if (type == 0 && clear_textures(game))
			ft_err_map("Invalid inputs in the mapfile\n", game->fd_str, game);
		i++;
	}
}

void	set_texture_null(t_game *game)
{
	game->all_textures->east_texture->texture = NULL;
	game->all_textures->west_texture->texture = NULL;
	game->all_textures->north_texture->texture = NULL;
	game->all_textures->south_texture->texture = NULL;
	game->ceiling_color[0] = -1;
	game->ceiling_color[1] = -1;
	game->ceiling_color[2] = -1;
	game->floor_color[0] = -1;
	game->floor_color[1] = -1;
	game->floor_color[2] = -1;
}

void	init_parse(char *map_file, t_game *game)
{
	set_texture_null(game);
	game->fd_str = NULL;
	if ((ft_strlen(map_file) < 4 || ft_strncmp(map_file \
		+ (ft_strlen(map_file) - 4), ".cub", 4) != 0) && clear_textures(game))
		ft_err_map("Invalid map format\n", game->fd_str, game);
	game->fd = open(map_file, O_RDWR);
	if (game->fd == -1 && clear_textures(game))
		ft_err_map("Can't open map\n", game->fd_str, game);
	game->fd_str = ft_read_all(game->fd, game, 1);
	if ((close(game->fd) == -1 || !game->fd_str) && clear_textures(game))
		ft_err_map("Error while allocate memory to the read buffer\n", \
			game->fd_str, game);
	sort_parse(game, 0, 0);
	free(game->fd_str);
}
