/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:43:25 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 13:44:44 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	handler_key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_and_exit_game(game, EXIT_SUCCESS);
	if (keycode == UP)
		game->movement_tab[0] = 1;
	if (keycode == DOWN)
		game->movement_tab[1] = 1;
	if (keycode == LEFT)
		game->movement_tab[2] = 1;
	if (keycode == RIGHT)
		game->movement_tab[3] = 1;
	if (keycode == ROT_RIGHT)
		game->movement_tab[4] = 1;
	if (keycode == ROT_LEFT)
		game->movement_tab[5] = 1;
	return (0);
}

int	handler_key_release(int keycode, t_game *game)
{
	if (keycode == ESC)
		free_and_exit_game(game, EXIT_SUCCESS);
	if (keycode == UP)
		game->movement_tab[0] = 0;
	if (keycode == DOWN)
		game->movement_tab[1] = 0;
	if (keycode == LEFT)
		game->movement_tab[2] = 0;
	if (keycode == RIGHT)
		game->movement_tab[3] = 0;
	if (keycode == ROT_RIGHT)
		game->movement_tab[4] = 0;
	if (keycode == ROT_LEFT)
		game->movement_tab[5] = 0;
	return (0);
}