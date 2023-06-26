/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:36:47 by Leo               #+#    #+#             */
/*   Updated: 2023/06/26 14:52:33 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "parsing.h"

void	set_texture_id(t_texture_info *all_textures)
{
	all_textures->west_texture->texture_id = 1;
	all_textures->north_texture->texture_id = 2;
	all_textures->east_texture->texture_id = 3;
	all_textures->south_texture->texture_id = 4;
}

void	init_game_window(t_game *game)
{
	game->window_height = 1024;
	game->window_width = 2048;
	game->mlx_win = mlx_new_window(game->mlx, game->window_width,
			game->window_height, "Cub3D");
	game->img = mlx_new_image(game->mlx, game->window_width,
			game->window_height);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	game->bits_per_pixel /= 8;
	if (game->game_tab_width >= game->game_tab_height)
		game->game_tab_max_encountred_cell = game->game_tab_width;
	else
		game->game_tab_max_encountred_cell = game->game_tab_height;
}

void	game_struct_set_null(t_game *game)
{
	game->all_textures = NULL;
	game->img = NULL;
	game->mlx_win = NULL;
	game->game_map = NULL;
}

void	game_init(char *map_path, t_game *game)
{
	game->movement_tab[0] = 0;
	game->movement_tab[1] = 0;
	game->movement_tab[2] = 0;
	game->movement_tab[3] = 0;
	game->movement_tab[4] = 0;
	game->movement_tab[5] = 0;
	game_struct_set_null(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->all_textures = init_all_textures();
	if (!game->all_textures)
		free_and_exit_game(game, EXIT_FAILURE);
	init_parse(map_path, game);
	set_texture_id(game->all_textures);
	init_game_window(game);
	game->game_cell_size = 64;
	game->speed = 4;
}
