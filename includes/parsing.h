/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:53:45 by Leo               #+#    #+#             */
/*   Updated: 2023/06/08 14:18:58 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdlib.h>
# include "header.h"

/*
**	Parsing structure pour gagner de l'espace dans la fonction 'fill_tab'
*/
typedef struct s_parsing
{
	int		x;
	int		y;
}	t_parsing;

#endif
