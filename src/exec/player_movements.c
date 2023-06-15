/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:06:45 by Leo               #+#    #+#             */
/*   Updated: 2023/06/15 14:13:17 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_move_up(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x + game->player_delta_x * 2;
	n_y = game->y + game->player_delta_y * 2;
	if (!is_wall(game, n_x, n_y))
	{
		game->x += game->player_delta_x * 2;
		game->y += game->player_delta_y * 2;
	}
	return ;
}

void	player_move_down(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x - game->player_delta_x * 2;
	n_y = game->y - game->player_delta_y * 2;
	if (!is_wall(game, n_x, n_y))
	{
		game->x -= game->player_delta_x * 2;
		game->y -= game->player_delta_y * 2;
	}
	return ;
}

void	player_move_left(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x + cos(game->player_angle + M_PI / 2) * 5;
	n_y = game->y + sin(game->player_angle + M_PI / 2) * 5;
	if (!is_wall(game, n_x, n_y))
	{
		game->x += cos(game->player_angle + M_PI / 2) * 5;
		game->y += sin(game->player_angle + M_PI / 2) * 5;
	}
	return ;
}

void	player_move_right(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x + cos(game->player_angle - M_PI / 2) * 5;
	n_y = game->y + sin(game->player_angle - M_PI / 2) * 5;
	if (!is_wall(game, n_x, n_y))
	{
		game->x += cos(game->player_angle - M_PI / 2) * 5;
		game->y += sin(game->player_angle - M_PI / 2) * 5;
	}
	return ;
}

void	player_movements(t_game *game)
{
	if (game->movement_tab[0])
		player_move_up(game);
	if (game->movement_tab[1])
		player_move_down(game);
	if (game->movement_tab[2])
		player_move_left(game);
	if (game->movement_tab[3])
		player_move_right(game);
	if (game->movement_tab[4])
		player_rotate_right(game);
	if (game->movement_tab[5])
		player_rotate_left(game);
}
