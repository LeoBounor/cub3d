/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_looking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:17:16 by Leo               #+#    #+#             */
/*   Updated: 2023/06/25 18:41:14 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Set the ray to look north, y is set to game->y rounded down to the
 * nearest multiple of game->game_cell_size (64 so bitshifted by 6) and x is
 * set to the intersection of the ray with the horizontal line at y
 * 
 * @param game: game struct
 * @param ray: current ray
 */
void	raycasting_looking_north(t_game *game, t_ray *ray)
{
	ray->y = (((int)game->y >> 6) << 6) - 0.01;
	ray->x = (game->y - ray->y) * ray->a_tan + game->x;
	ray->y_offset = -game->game_cell_size;
	ray->x_offset = -ray->y_offset * ray->a_tan;
	ray->texture = game->all_textures->north_texture;
	return ;
}

/**
 * @brief Set the ray to look south, y is set to game->y rounded up to the
 * nearest multiple of game->game_cell_size and we add 
 * 
 * @param game: game struct
 * @param ray: current ray
 */
void	raycasting_looking_south(t_game *game, t_ray *ray)
{
	ray->y = (((int)game->y >> 6) << 6) + game->game_cell_size;
	ray->x = (game->y - ray->y) * ray->a_tan + game->x;
	ray->y_offset = game->game_cell_size;
	ray->x_offset = -ray->y_offset * ray->a_tan;
	ray->texture = game->all_textures->south_texture;
	return ;
}

/**
 * @brief Set the ray to look straight, x and y are set to the player's
 * position and depth_of_field is set to stop the loop in raycasting.c
 * 
 * @param game: game struct
 * @param ray: current ray
 */
void	raycasting_looking_straight(t_game *game, t_ray *ray)
{
	ray->x = game->x;
	ray->y = game->y;
	ray->depth_of_field = game->game_tab_max_encountred_cell;
	return ;
}

/**
 * @brief Set the ray to look east, x is set to game->x rounded up to the
 * nearest multiple of game->game_cell_size (64 so bitshifted by 6) and y is
 * set to the intersection of the ray with the vertical line at x
 * 
 * @param game: game struct
 * @param ray: current ray
 */
void	raycasting_looking_east(t_game *game, t_ray *ray)
{
	ray->x = (((int)game->x >> 6) << 6) + game->game_cell_size;
	ray->y = (game->x - ray->x) * ray->a_tan + game->y;
	ray->x_offset = game->game_cell_size;
	ray->y_offset = -ray->x_offset * ray->a_tan;
	ray->texture = game->all_textures->east_texture;
	return ;
}

/**
 * @brief Set the ray to look west, x is set to game->x rounded down to the
 * nearest multiple of game->game_cell_size (64 so bitshifted by 6) and y is
 * set to the intersection of the ray with the vertical line at x
 * 
 * @param game: game struct
 * @param ray: current ray
 */
void	raycasting_looking_west(t_game *game, t_ray *ray)
{
	ray->x = (((int)game->x >> 6) << 6) - 0.01;
	ray->y = (game->x - ray->x) * ray->a_tan + game->y;
	ray->x_offset = -game->game_cell_size;
	ray->y_offset = -ray->x_offset * ray->a_tan;
	ray->texture = game->all_textures->west_texture;
	return ;
}
