/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:19:55 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 13:44:44 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	free_map(int **map, int n)
{
	while (n != -1)
	{
		free(map[n]);
		n--;
	}
	free(map);
	return (1);
}

int	clear_textures(t_game *game)
{
	if (game->all_textures->east_texture->texture)
		mlx_destroy_image(game->mlx, game->all_textures->east_texture->texture);
	if (game->all_textures->west_texture->texture)
		mlx_destroy_image(game->mlx, game->all_textures->west_texture->texture);
	if (game->all_textures->north_texture->texture)
		mlx_destroy_image(game->mlx,
			game->all_textures->north_texture->texture);
	if (game->all_textures->south_texture->texture)
		mlx_destroy_image(game->mlx,
			game->all_textures->south_texture->texture);
	if (game->all_textures->east_texture)
		free(game->all_textures->east_texture);
	if (game->all_textures->west_texture)
		free(game->all_textures->west_texture);
	if (game->all_textures->north_texture)
		free(game->all_textures->north_texture);
	if (game->all_textures->south_texture)
		free(game->all_textures->south_texture);
	if (game->all_textures)
		free(game->all_textures);
	return (1);
}
