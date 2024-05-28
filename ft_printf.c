/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:04 by smishos           #+#    #+#             */
/*   Updated: 2024/05/28 16:30:35 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_puthex(int num)
{
	int count = 0;
	if (num >= 16)
	{
		count += ft_puthex(num / 16);
		count += ft_putchar(num % 16 + '0');
	}
	else
	{
		if (num < 10)
			count += ft_putchar(num + '0');
		else
			count += ft_putchar(num + 'a' - 10);
	}
	return (count);
}


int ft_putstr(char *str)
{
	int count = 0;
	while (*str != '\0')
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}
int ft_putptr(void *ptr)
{
	int count = 0;
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr);
	return (count);
}
int ft_putnbr(int num)
{
	int count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		count += ft_putnbr(num / 10);
		count += ft_putchar(num % 10 + '0');
	}
	else
	{
		count += ft_putchar(num + '0');
	}
	return (count);
}


int ft_printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd')
			{
				int num = va_arg(args, int);
				count += ft_putnbr(num);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				count += ft_putstr(str);
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				count += ft_putchar(c);
			}
			else if (format[i] == 'x')
			{
				int num = va_arg(args, int);
				count += ft_puthex(num);
			}
			else if (format[i] == 'p')
			{
				void *ptr = va_arg(args, void *);
				count += ft_putptr(ptr);
			}
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}