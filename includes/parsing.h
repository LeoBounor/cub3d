/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:53:45 by Leo               #+#    #+#             */
/*   Updated: 2023/06/15 12:19:29 by lbounor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdlib.h>
# include "header.h"

typedef struct s_parsing
{
	int		x;
	int		y;
}	t_parsing;

void				init_parse(char *map_file, t_game *game);
void				check_map(t_game *game, int i, int j);
void				load_texture(t_game *game, t_texture *texture, int *i);
void				generate_tab(t_game *game, char *line);
void				load_color(t_game *game, int (*color)[3], int *i, int nb);

#endif
