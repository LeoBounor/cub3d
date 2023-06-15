/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:10:48 by lbounor           #+#    #+#             */
/*   Updated: 2023/06/15 14:52:54 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/**
 * @brief Get the distance between two points
 * 
 * @param ax: x coordinate of the first point
 * @param ay: y coordinate of the first point
 * @param bx: x coordinate of the second point
 * @param by: y coordinate of the second point
 * @return double: distance between the two points
 */
double	get_traveled_ray_distance(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

/**
 * @brief Assure that the angle is between 0 and 2 * PI
 * 
 * @param a: angle in radian
 * @return double: angle in radian between 0 and 2 * PI
 */
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
