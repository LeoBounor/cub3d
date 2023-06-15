/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:08:56 by jcollon           #+#    #+#             */
/*   Updated: 2023/06/15 14:08:58 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "header.h"

void				skip_to_next_parse(t_game *game, int *i);
void				skip_to_eol_or_eof(char *str, int *i);
void				skip_to_next_word(char *str, int *i);
char				*ft_read_all(int fd, t_game *game, int i);

#endif /* UTILS_H */