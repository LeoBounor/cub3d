/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:07:01 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 01:24:45 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Initialize a texture for the mlx
 * 
 * @param game: game structure
 * @param texture_path: path of the texture
 * @return t_texture: the texture
 */
t_texture	init_texture(t_game *game, char *texture_path)
{
	t_texture	new;

	new.texture = mlx_xpm_file_to_image(game->mlx, texture_path, \
	&new.width_img, &new.height_img);
	if (!new.texture)
	{
		free(texture_path);
		clear_textures(game);
		ft_err_map("Error loading texture\n", game->fd_str, game);
		new.texture_addr = NULL;
		new.width_img = 0;
		new.height_img = 0;
		new.bits_per_pixel = 0;
		new.line_length = 0;
		new.endian = 0;
		return (new);
	}
	new.texture_addr = mlx_get_data_addr(new.texture, \
	&new.bits_per_pixel, &new.line_length, &new.endian);
	new.bits_per_pixel /= 8;
	free(texture_path);
	return (new);
}

/**
 * @brief Get the texture path and then call init_texture
 * 
 * @param game: game structure
 * @param texture: the loaded texture
 * @param i: index of the string
 */
void	load_texture(t_game *game, t_texture *texture, int *i)
{
	int	tmp;

	if (texture->texture != NULL && clear_textures(game))
		ft_err_map("Too many texture parameters\n", game->fd_str, game);
	*i += 3;
	skip_to_next_word(game->fd_str, i);
	tmp = *i;
	skip_to_eol_or_eof(game->fd_str, i);
	if (game->fd_str[*i] == '\n')
		*i -= 1;
	while ((game->fd_str[*i] == ' ' || game->fd_str[*i] == '\t') && *i > tmp)
		*i -= 1;
	*texture = init_texture(game, ft_substr(game->fd_str, tmp, *i - tmp + 1));
}
