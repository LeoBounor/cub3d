/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:34:36 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/15 14:42:54 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Rotate the player to the right, 0.0174533 is the equivalent of 1
 * degree in radian
 * 
 * @param game: main game structure
 */
void	player_rotate_right(t_game *game)
{
	game->player_angle += 0.0174533;
	game->player_angle = assure_360_deg_angle(game->player_angle);
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
}

/**
 * @brief Rotate the player to the left, 0.0174533 is the equivalent of 1
 * degree in radian
 * 
 * @param game: main game structure
 */
void	player_rotate_left(t_game *game)
{
	game->player_angle -= 0.0174533;
	game->player_angle = assure_360_deg_angle(game->player_angle);
	game->player_delta_x = cos(game->player_angle) * 5;
	game->player_delta_y = sin(game->player_angle) * 5;
}
