/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:04:26 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 19:10:29 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	game_loop(t_game *game)
{
	player_movements(game);
	print_floor_and_ceiling(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, 0, 0);
	return (0);
}

void	game_render(t_game game)
{
	mlx_hook(game.mlx_win, 2, 1L << 0, &handler_key_press, &game);
	mlx_hook(game.mlx_win, 17, 1L << 0, &handler_close_mlx, &game);
	mlx_hook(game.mlx_win, 3, 1L << 0, &handler_key_release, &game);
	mlx_loop_hook(game.mlx, &game_loop, &game);
	mlx_loop(game.mlx);
	return ;
}

void	main_execution(char *map)
{
	t_game	game;

	game_init(map, &game);
	if (!map)
		free_and_exit_game(&game, EXIT_FAILURE);
	game_render(game);
	free_and_exit_game(&game, EXIT_SUCCESS);
}
