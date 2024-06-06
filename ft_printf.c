/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:04 by smishos           #+#    #+#             */
/*   Updated: 2024/06/06 16:09:08 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}

int ft_putnbr_unsigned(unsigned int n)
{
    int result = 0;
    if (n >= 10)
        result += ft_putnbr_unsigned(n / 10);
    result += ft_putchar(n % 10 + '0');
    return (result);
}

int ft_print_pointer(void *ptr)
{
    unsigned long addr = (unsigned long)ptr;
    ft_putstr("0x");
    return ft_print_hex(addr, 'x');
}

int	handle_format(char format, va_list *ap)
{
	if (format == 'c')
		ft_putchar(va_arg(*ap, int));
	else if (format == 's')
		ft_putstr(va_arg(*ap, char *));
	else if (format == 'p')
		ft_print_pointer(va_arg(*ap, void *));
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(*ap, int));
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(*ap, unsigned int));
	else if (format == 'x')
		ft_print_hex(va_arg(*ap, unsigned int), 'x');
	else if (format == 'X')
		ft_print_hex(va_arg(*ap, unsigned int), 'X');
	else if (format == '%')
		ft_putchar('%');
	return (1);
}

//This function needs to return the length of the string
int	ft_printf(const char *input, ...)
{
	va_list	ap;

	va_start(ap, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 0)
				break ;
			handle_format(*input, &ap); //This needs to return a length
		}
		else
			ft_putchar(*input);
		input++;
	}
	va_end(ap);
	return (0);
}
