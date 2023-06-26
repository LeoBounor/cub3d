/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:42:03 by Leo               #+#    #+#             */
/*   Updated: 2023/06/26 15:27:18 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Allocate memory for each texture and check if the allocation was
 * successful. If an allocation fails, the function returns a specific error
 * code corresponding to the texture that could not be allocated. Otherwise, it
 * returns code 5.
 * 
 * @param textures: structure containing all the textures
 * @return int: error code
 */
int	load_textures(t_texture_info *textures)
{
	textures->north_texture = 0;
	textures->east_texture = 0;
	textures->south_texture = 0;
	textures->west_texture = 0;
	textures->north_texture = ft_calloc(1, sizeof(t_texture));
	if (!textures->north_texture)
		return (1);
	textures->east_texture = ft_calloc(1, sizeof(t_texture));
	if (!textures->east_texture)
		return (2);
	textures->south_texture = ft_calloc(1, sizeof(t_texture));
	if (!textures->south_texture)
		return (3);
	textures->west_texture = ft_calloc(1, sizeof(t_texture));
	if (!textures->west_texture)
		return (4);
	return (5);
}

/**
 * @brief Allocate memory for t_texture_info and call load_textures to load the
 * textures in this structure. If load_textures returns an error code different
 * from 5, it means that there was an error during the allocation of the
 * textures.
 * 
 * @return t_texture_info*: pointer to the structure containing all the
 * textures
 */
t_texture_info	*init_all_textures(void)
{
	t_texture_info	*textures;
	int				ret;

	ret = 0;
	textures = ft_calloc(1, sizeof(t_texture_info));
	if (!textures)
		return (NULL);
	ret = load_textures(textures);
	if (ret != 5)
	{
		if (ret >= 1)
			free(textures->north_texture);
		if (ret >= 2)
			free(textures->east_texture);
		if (ret >= 3)
			free(textures->south_texture);
		if (ret >= 4)
			free(textures->west_texture);
		free(textures);
		return (NULL);
	}
	return (textures);
}

/**
 * @brief Get the texture pixel, texture_addr is the address of the first pixel
 * of the texture, texture->x and texture->y are the coordonates of the pixel.
 * 
 * @param texture: texture from which we want to get the pixel
 * @return int: color of the pixel
 */
int	get_texture_pixel(t_texture *texture)
{
	int	color;
	int	x;
	int	y;

	x = texture->x;
	y = texture->y;
	if (!texture)
		return (0);
	if (x < 0 || x >= texture->width_img || y < 0 || y >= texture->height_img)
		return (0);
	color = (*(int *)(texture->texture_addr + (x * texture->bits_per_pixel)
				+ (y * texture->line_length)));
	return (color);
}

/**
 * @brief Set the texture x coordonates according to the texture id and the
 * coordonates of the ray.
 * 
 * @param ray: ray from which we want to set the texture x coordonates
 */
void	set_texture_x_coordonates(t_ray *ray)
{
	if (ray->texture->texture_id % 2 == 0)
		ray->texture->x = ((ray->x / 64.0f) - (int)(ray->x / 64.0f))
			* ray->texture->width_img;
	else
		ray->texture->x = ((ray->y / 64.0f) - (int)(ray->y / 64.0f))
			* ray->texture->width_img;
	if (ray->texture->texture_id == 2 || ray->texture->texture_id == 3)
		ray->texture->x = ray->texture->width_img - ray->texture->x;
}
