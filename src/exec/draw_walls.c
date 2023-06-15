/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:23:46 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/15 15:26:33 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	remove_fisheye_effect(t_game *game, t_raycast *raycast, t_ray *ray)
{
	ray->traveled_distance = ray->traveled_distance
		* cos(assure_360_deg_angle(game->player_angle - raycast->ray_angle));
}

/**
 * @brief Draw the walls
 * 
 * @param game: main game structure
 * @param raycast: raycast structure
 * @param ray: ray structure
 * @param x: x position of the ray
 */
void	draw_walls(t_game *game, t_raycast *raycast, t_ray *ray, int x)
{
	float	wall_height;
	int		y;
	int		i;

	i = 0;
	remove_fisheye_effect(game, raycast, ray);
	wall_height = 128 * (float)game->window_height / ray->traveled_distance;
	set_texture_x_coordonates(ray);
	ray->texture->ratio = (double)(ray->texture->height_img)
		/ (double)wall_height;
	y = game->window_height / 2 - wall_height / 2;
	if (y < 0)
		i = -y;
	ray->texture->texture_y = i * ray->texture->ratio;
	while (i < wall_height && y + i < game->window_height)
	{
		ray->texture->texture_y += ray->texture->ratio;
		my_mlx_pixel_put(game, x, y + i,
			get_texture_pixel(ray->texture,
				ray->texture->texture_x, ray->texture->texture_y));
		i++;
	}
}
