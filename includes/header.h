/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:54:07 by Leo               #+#    #+#             */
/*   Updated: 2023/06/14 19:38:41 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# ifdef __linux__
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
#  define ROT_RIGHT 113
#  define ROT_LEFT 114
#  define ON_LINUX 1
# else
#  define ESC 53
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ROT_LEFT 124
#  define ROT_RIGHT 123
#  define ON_LINUX 0
# endif

# include "mlx.h"
# include "libft.h"
# include "execution.h"
# include "utils.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# define ERROR -1
# ifndef BONUS
#  define BONUS 0
# endif
# define PI 3.1415926535897932384
#endif