/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:34:36 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/26 15:20:30 by jcollon          ###   ########lyon.fr   */
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
	game->player_angle += 0.0174533 * 1.5;
	game->player_angle = assure_2_pi_angle(game->player_angle);
}

/**
 * @brief Rotate the player to the left, 0.0174533 is the equivalent of 1
 * degree in radian
 * 
 * @param game: main game structure
 */
void	player_rotate_left(t_game *game)
{
	game->player_angle -= 0.0174533 * 1.5;
	game->player_angle = assure_2_pi_angle(game->player_angle);
}
