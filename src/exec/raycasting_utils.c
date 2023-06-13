/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:10:48 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/12 23:25:22 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

double	get_traveled_ray_distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

double	assure_360_deg_angle(double a)
{
	double	two_pi;

	two_pi = 2 * M_PI;
	if (a >= two_pi)
		a -= (two_pi);
	if (a < 0)
		a += (two_pi);
	return (a);
}