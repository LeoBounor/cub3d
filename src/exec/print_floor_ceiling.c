/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:37:58 by Leo               #+#    #+#             */
/*   Updated: 2023/06/15 14:45:40 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned long	rgb_to_hexa(int color[3])
{
	return (((color[0] & 0xff) << 16) + ((color[1] & 0xff) << 8)
		+ (color[2] & 0xff));
}

/**
 * @brief Print the floor and the ceiling
 * 
 * @param game: game structure
 */
void	print_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->window_height)
	{
		x = 0;
		while (x < game->window_width)
		{
			if (y < game->window_height / 2)
				my_mlx_pixel_put(game, x, y, rgb_to_hexa(game->floor_color));
			else
				my_mlx_pixel_put(game, x, y, rgb_to_hexa(game->ceiling_color));
			x++;
		}
		y++;
	}
}
