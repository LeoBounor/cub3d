/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:06:45 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 13:44:44 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_move_up(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x + game->player_delta_x * game->speed;
	n_y = game->y + game->player_delta_y * game->speed;
	if (BONUS != 1 || !is_wall(game, n_x, n_y))
	{
		game->x += game->player_delta_x * game->speed;
		game->y += game->player_delta_y * game->speed;
	}
	return ;
}

void	player_move_down(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x - game->player_delta_x * game->speed;
	n_y = game->y - game->player_delta_y * game->speed;
	if (BONUS != 1 || !is_wall(game, n_x, n_y))
	{
		game->x -= game->player_delta_x * game->speed;
		game->y -= game->player_delta_y * game->speed;
	}
	return ;
}

void	player_move_left(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x + cos(game->player_angle + M_PI / 2) * game->speed;
	n_y = game->y + sin(game->player_angle + M_PI / 2) * game->speed;
	if (BONUS != 1 || !is_wall(game, n_x, n_y))
	{
		game->x += cos(game->player_angle + M_PI / 2) * game->speed;
		game->y += sin(game->player_angle + M_PI / 2) * game->speed;
	}
	return ;
}

void	player_move_right(t_game *game)
{
	float	n_x;
	float	n_y;

	n_x = game->x + cos(game->player_delta_x - M_PI / 2) * game->speed;
	n_y = game->y + sin(game->player_delta_y - M_PI / 2) * game->speed;
	if (BONUS != 1 || !is_wall(game, n_x, n_y))
	{
		game->x += cos(game->player_delta_x - M_PI / 2) * game->speed;
		game->y += sin(game->player_delta_y - M_PI / 2) * game->speed;
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
