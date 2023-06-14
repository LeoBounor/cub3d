/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:51:49 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 11:18:16 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	raycasting_angle_interpeter(int vertical, t_game *game, t_ray *ray,
	float ray_angle)
{
	ray_angle = assure_360_deg_angle(ray_angle);
	if (!vertical)
	{
		ray->a_tan = -1 / tan(ray_angle);
		if (ray_angle > M_PI)
			raycasting_horizontal_looking_up(game, ray);
		else if (ray_angle < M_PI && ray_angle)
			raycasting_horizontal_looking_down(game, ray);
		else if (ray_angle == 0 || ray_angle == M_PI)
			raycasting_looking_straight(game, ray);
	}
	else if (vertical == 1)
	{
		ray->a_tan = -tan(ray_angle);
		if (ray_angle > M_PI / 2 && ray_angle < 3 * M_PI / 2)
			raycasting_vertical_looking_left(game, ray);
		else if (ray_angle < M_PI / 2 || ray_angle > 3 * M_PI / 2)
			raycasting_vertical_looking_right(game, ray);
		else if (ray_angle == 0 || ray_angle == M_PI)
			raycasting_looking_straight(game, ray);
	}
}

void	check_ray_collision(t_raycast *raycast, t_ray *ray,
	t_game *game, int vertical)
{
	ray->traveled_distance = 10000000;
	ray->depth_of_field = 0;
	raycasting_angle_interpeter(vertical, game, ray, raycast->ray_angle);
	while (ray->depth_of_field < game->game_tab_max_encountred_cell)
	{
		ray->map_x = (int)ray->x >> 6;
		ray->map_y = (int)ray->y >> 6;
		if (is_in_map_limits(game, ray->map_x, ray->map_y)
			&& game->game_tab[ray->map_y][ray->map_x] == 1)
		{
			ray->depth_of_field = game->game_tab_max_encountred_cell;
			ray->traveled_distance = get_traveled_ray_distance(game->x,
					game->y, ray->x, ray->y);
		}
		else
		{
			ray->x += ray->x_offset;
			ray->y += ray->y_offset;
			ray->depth_of_field ++;
		}
	}
}

void	raycasting(t_game *game)
{
	int			x;
	t_raycast	*raycast;

	x = 0;
	raycast = game->raycast;
	raycast->ray_angle = assure_360_deg_angle(game->player_angle + \
	(0.0174533 * 25));
	while (x < game->window_width)
	{
		check_ray_collision(raycast, &raycast->vertical_ray, game, 1);
		check_ray_collision(raycast, &raycast->horizontal_ray, game, 0);
		if (raycast->horizontal_ray.traveled_distance <= \
		raycast->vertical_ray.traveled_distance)
			draw_walls(game, raycast, &raycast->horizontal_ray, x);
		else
			draw_walls(game, raycast, &raycast->vertical_ray, x);
		raycast->ray_angle = assure_360_deg_angle(raycast->ray_angle - \
		(0.0174533 * 50) / game->window_width);
		x++;
	}
}
