/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:12:16 by Leo               #+#    #+#             */
/*   Updated: 2023/06/12 23:36:54 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	is_in_map_limits(t_game *game, int x, int y)
{
	if ((x >= 0 && y >= 0) && x < game->game_tab_width
		&& y < game->game_tab_height)
		return (1);
	return (0);
}

int	is_in_window_limits(t_game *game, float x, float y)
{
	if (x < 0 || (x / game->game_cell_size) > game->window_width || y < 0 || \
		(y / game->game_cell_size) > game->window_height)
		return (0);
	return (1);
}

/*
**	Vérifie si une collision avec un mur se produit aux coordonnées (x, y). 
**
**	Si les coordonnées sont à l'extérieur des limites de la fenêtre ou si les 
**	cases adjacentes dans la grille de jeu contiennent un mur.
**	La fonction retourne 1 en cas de collision et 0 sinon.
**	On ajoute une précision de 3 pixels à la position pour éviter les collisions
**	avec les murs.
*/
int	is_wall(t_game *game, float x, float y)
{
	if (!is_in_window_limits(game, x, y))
		return (1);
	if (game->game_tab[(int)y / game->game_cell_size][(int)x / \
	game->game_cell_size] == 1 || game->game_tab[((int)y + 3) / \
	game->game_cell_size][(int)x / game->game_cell_size] == 1 || \
	game->game_tab[(int)y / game->game_cell_size][((int)x + 3) / \
	game->game_cell_size] == 1 || game->game_tab[((int)y - 3) / \
	game->game_cell_size][(int)x / game->game_cell_size] == 1 || \
	game->game_tab[(int)y / game->game_cell_size][((int)x - 3) / \
	game->game_cell_size] == 1)
		return (1);
	return (0);
}
