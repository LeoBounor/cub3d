/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 10:06:57 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 23:54:44 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	init_color(t_game *game, int *i, int (*color)[3], int nb)
{
	if ((*color)[nb] != -1 && clear_textures(game))
		ft_err_map("Invalide color format\n", game->fd_str, game);
	(*color)[nb] = ft_atoi((game->fd_str + *i), i);
	if ((*color)[nb] < 0 || (*color)[nb] > 255)
	{
		clear_textures(game);
		ft_err_map("Invalide color format\n", game->fd_str, game);
	}
	return ((*color)[nb]);
}

void	skip_first_arg(int *i, int nb, t_game *game)
{
	if (nb == 0)
		*i += 2;
	skip_to_next_word(game->fd_str, i);
	if ((game->fd_str[*i] == '\n' || \
	!ft_isdigit(game->fd_str[*i])) && clear_textures(game))
		ft_err_map("Invalide color format\n", game->fd_str, game);
}

void	load_color(t_game *game, int (*color)[3], int *i, int nb)
{
	skip_first_arg(i, nb, game);
	(*color)[nb] = init_color(game, i, color, nb);
	skip_to_next_word(game->fd_str, i);
	if (nb != 2)
		while (game->fd_str[*i] && game->fd_str[*i] != ',')
			if (game->fd_str[*i++] != ' ' && game->fd_str[*i] != '\t' && \
			(*i)++)
				if (clear_textures(game))
					ft_err_map("Invalide color format\n", game->fd_str, game);
	if (game->fd_str[*i] == ',' && nb != 2)
		*i += 1;
	if (nb != 2)
		load_color(game, color, i, nb + 1);
	else
	{
		while (game->fd_str[*i] && game->fd_str[*i] != '\n')
		{
			if (!ft_isdigit(game->fd_str[*i]) && game->fd_str[*i] != ' ' \
			&& clear_textures(game))
				ft_err_map("invalid color format", game->fd_str, game);
			*i += 1;
		}
	}
}
