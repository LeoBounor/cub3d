/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:12:16 by Leo               #+#    #+#             */
/*   Updated: 2023/06/21 01:11:34 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Check if the given coordinates are inside the map limits.
 * 
 * @param game: game structure
 * @param x: x coordinate on the game grid
 * @param y: y coordinate on the game grid
 * @return int: 1 if the coordinates are inside the map limits, 0 otherwise
 */
int	is_in_map_limits(t_game *game, int x, int y)
{
	if ((x >= 0 && y >= 0) && x < game->game_tab_width
		&& y < game->game_tab_height)
		return (1);
	return (0);
}

/**
 * @brief Check if the given coordinates are inside the window limits.
 * 
 * @param game: game structure
 * @param x: x coordinate
 * @param y: y coordinate
 * @return int: 1 if the coordinates are inside the window limits, 0 otherwise
 */
int	is_in_window_limits(t_game *game, float x, float y)
{
	if (x < 0 || (x / game->game_cell_size) > game->window_width || y < 0 || \
		(y / game->game_cell_size) > game->window_height)
		return (0);
	return (1);
}

/**
 * @brief Check if there is a wall at the given coordinates, if the coordinates
 * are outside the window limits or if the adjacent cells in the game grid
 * contain a wall then the function returns 1 in case of collision and 0
 * otherwise. We add a precision of 3 pixels to the position to avoid
 * collisions in the walls.
 * 
 * @param game: game structure
 * @param x: x coordinate
 * @param y: y coordinate
 * @return int: 1 if there is a collision, 0 otherwise
 */
int	is_wall(t_game *game, float x, float y)
{
	if (!is_in_window_limits(game, x, y))
		return (1);
	if (game->game_map[(int)y / game->game_cell_size][(int)x / \
	game->game_cell_size] == 1 || game->game_map[((int)y + 3) / \
	game->game_cell_size][(int)x / game->game_cell_size] == 1 || \
	game->game_map[(int)y / game->game_cell_size][((int)x + 3) / \
	game->game_cell_size] == 1 || game->game_map[((int)y - 3) / \
	game->game_cell_size][(int)x / game->game_cell_size] == 1 || \
	game->game_map[(int)y / game->game_cell_size][((int)x - 3) / \
	game->game_cell_size] == 1)
		return (1);
	return (0);
}
