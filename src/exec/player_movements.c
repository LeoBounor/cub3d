/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:06:45 by Leo               #+#    #+#             */
/*   Updated: 2023/06/26 14:14:39 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_move_up(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + cos(game->player_angle) * 5 * 2;
	new_y = game->y + sin(game->player_angle) * 5 * 2;
	if (!is_wall(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	return ;
}

void	player_move_down(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x - cos(game->player_angle) * 5 * 2;
	new_y = game->y - sin(game->player_angle) * 5 * 2;
	if (!is_wall(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	return ;
}

void	player_move_left(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + cos(game->player_angle + M_PI_2) * 5;
	new_y = game->y + sin(game->player_angle + M_PI_2) * 5;
	if (!is_wall(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
	}
	return ;
}

void	player_move_right(t_game *game)
{
	float	new_x;
	float	new_y;

	new_x = game->x + cos(game->player_angle - M_PI_2) * 5;
	new_y = game->y + sin(game->player_angle - M_PI_2) * 5;
	if (!is_wall(game, new_x, new_y))
	{
		game->x = new_x;
		game->y = new_y;
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
