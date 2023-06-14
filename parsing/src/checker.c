/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:33:03 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 01:19:58 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/**
 * @brief Check if the map is surrounded by walls, vertically then horizontally
 * 
 * @param game: game structure
 * @return 1 if the map is not surrounded by walls, 0 otherwise
 */
int	check_border(t_game *game)
{
	int	i;

	i = 0;
	while (i != game->game_tab_height)
	{
		if (game->game_tab[i][0] != 1 && game->game_tab[i][0] != 2)
			return (1);
		else if (game->game_tab[i][game->game_tab_width - 1] != 1 \
			&& game->game_tab[i][game->game_tab_width - 1] != 2)
			return (1);
		i++;
	}
	i = 0;
	while (game->game_tab_width != i)
	{
		if (game->game_tab[0][i] != 1 && game->game_tab[0][i] != 2)
			return (1);
		else if (game->game_tab[game->game_tab_height - 1][i] != 1 \
			&& game->game_tab[game->game_tab_height - 1][i] != 2)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Check if the player is in the map and set the player position and
 * angle, a square in the map is 64px and we add 32 to center the player
 * 
 * @param game: game structure 
 * @param i: index of the line
 * @param j: index of the column
 */
void	check_player_position(t_game *game, int i, int j)
{
	if (game->game_tab[i][j] == 'N' - '0' || game->game_tab[i][j] == 'S' - '0' \
	|| game->game_tab[i][j] == 'E' - '0' || game->game_tab[i][j] == 'W' - '0')
	{
		game->y = i * 64 + 32;
		game->x = j * 64 + 32;
		if (game->game_tab[i][j] == 'N' - '0')
			game->player_angle = (3 * M_PI) / 2;
		else if (game->game_tab[i][j] == 'S' - '0')
			game->player_angle = M_PI / 2;
		else if (game->game_tab[i][j] == 'E' - '0')
			game->player_angle = 0;
		else if (game->game_tab[i][j] == 'W' - '0')
			game->player_angle = M_PI;
		game->game_tab[i][j] = 0;
	}
}

/**
 * @brief Check if a square is surrounded by walls
 * 
 * @param game: game structure
 * @param i: index of square in the line
 * @param j: index of square in the column
 */
void	check_surronded_by_wall(t_game *game, int i, int j)
{
	if ((game->game_tab[i + 1][j] == 2 || game->game_tab[i - 1][j] == 2 || \
	game->game_tab[i][j + 1] == 2 || game->game_tab[i][j - 1] == 2) && \
	free_map(game->game_tab, game->game_tab_height - 1) && clear_textures(game))
		ft_err_map("Map error\n", game->fd_str, game);
}

/**
 * @brief Replace all 2 by 0 in the map
 * 
 * @param game: game structure
 */
void	replace_to_zero(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != game->game_tab_height)
	{
		j = 0;
		while (j != game->game_tab_width)
		{
			if (game->game_tab[i][j] == 2)
				game->game_tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

/**
 * @brief Check if the map is valid, if not, free the map and exit the program
 * 
 * @param game: game structure 
 * @param i: index of the line
 * @param j: index of the column
 */
void	check_map(t_game *game, int i, int j)
{
	game->x = -1;
	game->y = -1;
	if (check_border(game) && clear_textures(game) && \
		free_map(game->game_tab, game->game_tab_height - 1))
		ft_err_map("Border error\n", game->fd_str, game);
	while (i != game->game_tab_height - 1)
	{
		j = 1;
		while (j != game->game_tab_width - 1)
		{
			check_player_position(game, i, j);
			if (game->game_tab[i][j] == 0 || game->game_tab[i][j] == 'N' || \
				game->game_tab[i][j] == 'S' || game->game_tab[i][j] == 'E' || \
				game->game_tab[i][j] == 'W')
				check_surronded_by_wall(game, i, j);
			j++;
		}
		i++;
	}
	if ((game->x == -1 || game->game_tab_height < 3 || game->game_tab_width < \
	3) && free_map(game->game_tab, game->game_tab_height - 1) \
	&& clear_textures(game))
		ft_err_map("Map error\n", game->fd_str, game);
	replace_to_zero(game);
}
