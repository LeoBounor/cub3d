/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:51:49 by Leo               #+#    #+#             */
/*   Updated: 2023/06/26 15:14:50 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <float.h>

/**
 * @brief Set the ray x, y and texture depending on the angle of the ray
 * 
 * @param vertical: 1 if it should check for a vertical wall (east or west) and
 * 0 if it should check for a horizontal wall (north or south)
 * @param game: game struct
 * @param ray: current ray
 * @param ray_angle: angle of the ray
 */
void	raycasting_angle_interpeter(char vertical, t_game *game, t_ray *ray,
	double ray_angle)
{
	ray_angle = assure_2_pi_angle(ray_angle);
	if (!vertical)
	{
		ray->a_tan = -1 / tan(ray_angle);
		if (ray_angle > M_PI)
			raycasting_looking_north(game, ray);
		else if (ray_angle < M_PI && ray_angle)
			raycasting_looking_south(game, ray);
		else
			raycasting_looking_straight(game, ray);
	}
	else
	{
		ray->a_tan = -tan(ray_angle);
		if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
			raycasting_looking_west(game, ray);
		else if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
			raycasting_looking_east(game, ray);
		else
			raycasting_looking_straight(game, ray);
	}
}

/**
 * @brief Check if the ray is colliding with a wall
 * 
 * @param ray_angle: angle of the ray
 * @param ray: current ray
 * @param game: game struct
 * @param vertical: 1 if the ray is vertical, 0 if horizontal
 */
void	check_ray_collision(double ray_angle, t_ray *ray,
	t_game *game, char vertical)
{
	ray->traveled_distance = FLT_MAX;
	ray->depth_of_field = 0;
	raycasting_angle_interpeter(vertical, game, ray, ray_angle);
	while (ray->depth_of_field < game->game_tab_max_encountred_cell)
	{
		ray->map_x = (int)ray->x >> 6;
		ray->map_y = (int)ray->y >> 6;
		if (is_in_map_limits(game, ray->map_x, ray->map_y)
			&& game->game_map[ray->map_y][ray->map_x] == 1)
		{
			ray->depth_of_field = game->game_tab_max_encountred_cell;
			ray->traveled_distance = get_traveled_distance(game->x, game->y,
					ray->x, ray->y);
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field++;
		}
	}
}

/**
 * @brief Shoot a ray from the player to the wall and draw the wall, check
 * vertical and horizontal wall collision and draw the closest wall
 * 
 * @param game: game struct
 */
void	raycasting(t_game *game)
{
	int			x;
	int			fov;
	t_ray		rays[2];
	double		ray_angle;

	x = 0;
	fov = 29;
	ray_angle = assure_2_pi_angle(game->player_angle + (0.0174533 * fov));
	while (x < game->window_width)
	{
		check_ray_collision(ray_angle, &rays[0], game, 1);
		check_ray_collision(ray_angle, &rays[1], game, 0);
		if (rays[0].traveled_distance <= rays[1].traveled_distance)
			draw_walls(game, ray_angle, &rays[0], x);
		else
			draw_walls(game, ray_angle, &rays[1], x);
		ray_angle -= (0.0174533 * fov * 2) / game->window_width;
		ray_angle = assure_2_pi_angle(ray_angle);
		x++;
	}
}
