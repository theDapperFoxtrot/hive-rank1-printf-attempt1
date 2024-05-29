/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:05:04 by smishos           #+#    #+#             */
/*   Updated: 2024/05/29 16:47:15 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *input, ...)
{
	va_list ap;
	// cspdiuxX%
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == 'c') // char
				ft_putchar(va_arg(ap, int));
			else if (*input == 's') // string
				ft_putstr(va_arg(ap, char *));
			else if (*input == 'p') // pointer
				ft_putstr(va_arg(ap, void *));
			else if (*input == 'd' || *input == 'i') // decimal or integer
				ft_putnbr(va_arg(ap, int));
			else if (*input == 'u') // unsigned int
				ft_putnbr(va_arg(ap, unsigned int));
			else if (*input == 'x') // hexadecimal
				ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
			else if (*input == 'X') // hexadecimal
				ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
			else if (*input == '%') // percentage
				ft_putchar('%');
		}
		else
			ft_putchar(*input);
		input++;
	}

	return (0);
}