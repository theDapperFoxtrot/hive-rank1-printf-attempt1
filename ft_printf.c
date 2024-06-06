/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:04 by smishos           #+#    #+#             */
/*   Updated: 2024/06/06 17:58:29 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	result;

	result = 0;
	if (n >= 10)
		result += ft_putnbr_unsigned(n / 10);
	result += ft_putchar(n % 10 + '0');
	return (result);
}

int	ft_print_pointer(void *ptr)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr("0x");
	return (ft_print_hex(addr, 'x'));
}

int	handle_format(char format, va_list *ap)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_putchar(va_arg(*ap, int));
	else if (format == 's')
		result = ft_putstr(va_arg(*ap, char *));
	else if (format == 'p')
		result = ft_print_pointer(va_arg(*ap, void *));
	else if (format == 'd' || format == 'i')
		result = ft_putnbr(va_arg(*ap, int));
	else if (format == 'u')
		result = ft_putnbr_unsigned(va_arg(*ap, unsigned int));
	else if (format == 'x')
		result = ft_print_hex(va_arg(*ap, unsigned int), 'x');
	else if (format == 'X')
		result = ft_print_hex(va_arg(*ap, unsigned int), 'X');
	else if (format == '%')
		result = ft_putchar('%');
	return (result);
}

int	accumulate_length(size_t *total_len, int len)
{
	if (len == -1)
		return (-1);
	*total_len += len;
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	total_len;
	int		len;

	total_len = 0;
	va_start(ap, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 0)
				break ;
			len = handle_format(*input, &ap);
		}
		else
			len = ft_putchar(*input);
		if (accumulate_length(&total_len, len) == -1)
			return (-1);
		input++;
	}
	va_end(ap);
	return (total_len);
}
