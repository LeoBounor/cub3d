/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:34:36 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/14 18:58:07 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	player_rotate_right(t_game *game)
{
	game->player_angle += 0.0174533;
	game->player_angle = assure_360_deg_angle(game->player_angle);
	game->player_delta_x = cos(game->player_angle) * 3;
	game->player_delta_y = sin(game->player_angle) * 3;
}

void	player_rotate_left(t_game *game)
{
	game->player_angle -= 0.0174533;
	game->player_angle = assure_360_deg_angle(game->player_angle);
	game->player_delta_x = cos(game->player_angle) * 3;
	game->player_delta_y = sin(game->player_angle) * 3;
}
