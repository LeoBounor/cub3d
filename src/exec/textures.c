/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:42:03 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 18:55:51 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

/*
**	Alloue de la mémoire pour chaque texture et vérifie si l'allocation a réussi.
**	Si une allocation échoue, la fonction renvoie un code d'erreur spécifique 
**	correspondant à la texture qui n'a pas pu être allouée.
**	Sinon, elle renvoie le code 5.
*/
int	load_textures(t_texture_info *textures)
{
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

/*
**	Alloue de la mémoire pour t_texture_info. 
**	Ensuite, elle appelle load_textures pour charger les textures
**	dans cette structure.
**	Si load_textures renvoie un code d'erreur différent de 5,
**	cela signifie qu'il y a eu une erreur lors de l'allocation des textures.
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
		if (ret <= 1)
			free(textures->north_texture);
		if (ret <= 2)
			free(textures->east_texture);
		if (ret <= 3)
			free(textures->south_texture);
		if (ret <= 4)
			free(textures->west_texture);
		free(textures);
		return (NULL);
	}
	return (textures);
}

/*
**	Calcule l'adresse mémoire du pixel correspondant dans la texture.
**	Utilise un cast pour interpréter cette adresse mémoire comme un
**	pointeur vers un entier (int *).
**	Enfin, récupère la couleur du pixel en déréférençant le pointeur obtenu
**	à partir de l'adresse mémoire calculée.
*/
int	get_texture_pixel(t_texture *texture, int x, int y)
{
	int	color;

	if (!texture)
		return (0);
	if (x < 0 || x >= texture->width_img || y < 0 || y >= texture->height_img)
		return (0);
	color = (*(int *)(texture->texture_addr + (x * texture->bits_per_pixel)
				+ (y * texture->line_length)));
	return (color);
}

void	set_texture_x_coordonates(t_ray *ray)
{
	if (ray->texture->texture_id % 2 == 0)
		ray->texture->texture_x = ((ray->x / 64.0f) - (int)(ray->x / 64.0f))
			* ray->texture->width_img;
	else
		ray->texture->texture_x = ((ray->y / 64.0f) - (int)(ray->y / 64.0f))
			* ray->texture->width_img;
	if (ray->texture->texture_id == 3 || ray->texture->texture_id == 4)
		ray->texture->texture_x = ray->texture->width_img
			- ray->texture->texture_x;
}
