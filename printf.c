/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:29:06 by root              #+#    #+#             */
/*   Updated: 2025/01/07 01:03:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

static void ft_printf_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void ft_printf_str(char *str, int *count)
{
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_printf_char(str[i], count);
		i++;
	}
}

static void ft_printf_integer(int n, int *count)
{
	if (n == -2147483648)
		ft_printf_str("-2147483648", count);
	if (n < 0)
	{
		ft_printf_char('-', count);
		n *= -1;
	}
	if (n > 9)
	{
		ft_printf_integer(n / 10, count);
		ft_printf_integer(n % 10, count);
	}
	else 
		ft_printf_char(n + 48, count);
}

static void ft_printf_hexa(unsigned int n, int *count)
{
	char *hexa = "0123456789abcdef";
	if (n > 15)
	{
		ft_printf_hexa(n / 16, count);
		ft_printf_hexa(n % 16, count);
	}
	else
		ft_printf_char(hexa[n], count);
}

int ft_printf(char *str, ...)
{
	va_list args;
	int i = 0;
	int count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_printf_str(va_arg(args, char *), &count);
			else if (str[i] == 'd')
				ft_printf_integer(va_arg(args, int), &count);
			else if (str[i] == 'x')
				ft_printf_hexa(va_arg(args, unsigned int), &count);
			else
				ft_printf_char(str[i], &count);
		}
		else
			ft_printf_char(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	ft_printf("%s, %d, %x\n", "heyyocmoilebg", -8545887, 14589555);
	printf("%s, %d, %x\n", "heyyocmoilebg", -8545887, 14589555);
}