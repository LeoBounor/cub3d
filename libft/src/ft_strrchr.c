/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <jcollon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:02:12 by jcollon           #+#    #+#             */
/*   Updated: 2023/02/03 17:01:08 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char) c)
	{
		if (i == 0)
			return (0);
		i--;
	}
	return ((char *) str + i);
}
