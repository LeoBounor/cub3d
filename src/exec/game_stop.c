/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_stop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:34:01 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 13:44:44 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_game(t_game *game)
{
	clear_textures(game);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->game_tab)
		free_map(game->game_tab, game->game_tab_height - 1);
	stop_mlx(game);
	if (game->raycast)
		free(game->raycast);
}

void	free_and_exit_game(t_game *game, int exit_ret)
{
	if (game)
		free_game(game);
	exit(exit_ret);
}

int	handler_close_mlx(t_game *game)
{
	free_and_exit_game(game, EXIT_SUCCESS);
	return (1);
}