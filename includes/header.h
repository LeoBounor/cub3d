/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbounor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:54:07 by Leo               #+#    #+#             */
/*   Updated: 2023/06/13 09:57:14 by lbounor          ###   ########.fr       */
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
#  include "../mlx_linux/mlx.h"
# else
#  define ESC 53
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ROT_LEFT 124
#  define ROT_RIGHT 123
#  define ON_LINUX 0
#  include "../mlx/mlx.h"
# endif

# include "../libft/libft.h"
# include "execution.h"
# include "parsing.h"
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