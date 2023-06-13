/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:04:31 by Leo               #+#    #+#             */
/*   Updated: 2023/06/12 23:05:04 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > game->window_width - 1 || y < 0
		|| y > game->window_height - 1)
		return ;
	dst = game->addr + (y * game->line_length + x * (game->bits_per_pixel));
	*(unsigned int *)dst = color;
}
