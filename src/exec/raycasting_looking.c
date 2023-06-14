/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_looking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:17:16 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 11:18:00 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	raycasting_horizontal_looking_up(t_game *game, t_ray *ray)
{
	ray->y = (((int)game->y >> 6) << 6) - 0.01;
	ray->x = (game->y - ray->y) * ray->a_tan + game->x;
	ray->y_offset = -game->game_cell_size;
	ray->x_offset = -ray->y_offset * ray->a_tan;
	ray->texture = game->all_textures->north_texture;
	return ;
}

void	raycasting_horizontal_looking_down(t_game *game, t_ray *ray)
{
	ray->y = (((int)game->y >> 6) << 6) + game->game_cell_size;
	ray->x = (game->y - ray->y) * ray->a_tan + game->x;
	ray->y_offset = game->game_cell_size;
	ray->x_offset = -ray->y_offset * ray->a_tan;
	ray->texture = game->all_textures->south_texture;
	return ;
}

void	raycasting_looking_straight(t_game *game, t_ray *ray)
{
	ray->x = game->x;
	ray->y = game->y;
	ray->depth_of_field = game->game_tab_max_encountred_cell;
	return ;
}

void	raycasting_vertical_looking_right(t_game *game, t_ray *ray)
{
	ray->x = (((int)game->x >> 6) << 6) + game->game_cell_size;
	ray->y = (game->x - ray->x) * ray->a_tan + game->y;
	ray->x_offset = game->game_cell_size;
	ray->y_offset = -ray->x_offset * ray->a_tan;
	ray->texture = game->all_textures->east_texture;
	return ;
}

void	raycasting_vertical_looking_left(t_game *game, t_ray *ray)
{
	ray->x = (((int)game->x >> 6) << 6) - 0.01;
	ray->y = (game->x - ray->x) * ray->a_tan + game->y;
	ray->x_offset = -game->game_cell_size;
	ray->y_offset = -ray->x_offset * ray->a_tan;
	ray->texture = game->all_textures->west_texture;
	return ;
}
