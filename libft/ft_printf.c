/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:08:26 by vducoulo          #+#    #+#             */
/*   Updated: 2022/10/25 23:22:26 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	printandgive(const char *str)
{
	static size_t	i;

	if (!i)
		i = 0;
	while (str[i] && str[i] != '%')
		ft_putchar_fd(str[i++], 1);
	i += 2;
	return (str[i - 1]);
}

int	printme(char type, va_list arg)
{
	int	res;

	res = 0;
	if (type == 'c')
		res += ft_putchar_fd(va_arg(arg, int), 1);
	else if (type == 's')
		res += ft_putstr_fd(va_arg(arg, char *), 1);
	else if ((type == 'd' || type == 'i'))
		res += ft_putnbr_fd(va_arg(arg, int), 1);
	else if (type == 'u')
		res += ft_putnbr_unsigned_fd(va_arg(arg, unsigned int), 1);
	else if (type == 'x' || type == 'X')
		res += ft_convert_base_printf_fd(va_arg(arg, unsigned int),
				type, 1);
	else if (type == 'p')
		res += ft_convert_base_printf_fd(va_arg(arg, unsigned long),
				type, 1);
	else
		res += ft_putchar_fd(type, 1);
	return (res);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		res;
	size_t	i;

	i = 0;
	res = 0;
	va_start(args, input);
	while (input[i++])
	{
		if (input[i - 1] == '%' && input[i])
			res += printme(input[i++], args);
		else
			res += ft_putchar_fd(input[i - 1], 1);
	}
	va_end(args);
	return (res);
}
