/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo <Leo@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:52:39 by Leo               #+#    #+#             */
/*   Updated: 2023/06/12 23:51:44 by Leo              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		main_execution(argv[1]);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (EXIT_FAILURE);
}
