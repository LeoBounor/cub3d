/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:33:03 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 13:44:44 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
**	On regarde d'abord si verticalement le tab est rempli de 1 ou 2,
**	puis horizontalement. Si ce n'est pas le cas, on retourne 1.
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

/*
**	Une case du tableau représente 64 et on ajoute 32 pour centrer le player
**	Puis on calcule l'angle du player en fonction de sa position.
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

void	check_surronded_by_wall(t_game *game, int i, int j)
{
	if ((game->game_tab[i + 1][j] == 2 || game->game_tab[i - 1][j] == 2 || \
	game->game_tab[i][j + 1] == 2 || game->game_tab[i][j - 1] == 2) && \
	free_map(game->game_tab, game->game_tab_height - 1) && clear_textures(game))
		ft_err_map("Map error\n", game->fd_str, game);
}

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
			printf("%d", game->game_tab[i][j]);
			j++;
		}
		i++;
	}
}

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
