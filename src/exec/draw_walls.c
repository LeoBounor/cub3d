/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:23:46 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/26 14:47:30 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	remove_fisheye_effect(t_game *game, double ray_angle, t_ray *ray)
{
	ray->traveled_distance = ray->traveled_distance
		* cos(assure_2_pi_angle(game->player_angle - ray_angle));
}

/**
 * @brief Draw the walls
 * 
 * @param game: main game structure
 * @param ray_angle: the ray angle
 * @param ray: current ray
 * @param x: x position of the ray
 */
void	draw_walls(t_game *game, double ray_angle, t_ray *ray, int x)
{
	float	wall_height;
	int		y;
	int		i;

	i = 0;
	remove_fisheye_effect(game, ray_angle, ray);
	wall_height = 128 * (float)game->window_height / ray->traveled_distance;
	set_texture_x_coordonates(ray);
	ray->texture->ratio = (double)(ray->texture->height_img)
		/ (double)wall_height;
	y = game->window_height / 2 - wall_height / 2;
	if (y < 0)
		i = -y;
	ray->texture->y = i * ray->texture->ratio;
	while (i < wall_height && y + i < game->window_height)
	{
		ray->texture->y += ray->texture->ratio;
		my_mlx_pixel_put(game, x, y + i,
			get_texture_pixel(ray->texture));
		i++;
	}
}
