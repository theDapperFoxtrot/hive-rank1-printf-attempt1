/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:28:44 by smishos           #+#    #+#             */
/*   Updated: 2024/06/06 14:47:05 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	result;

	result = 0;
	if (!str)
	{
		result += ft_putstr("(null)");
	}
	else
	{
		while (*str)
		{
			result += ft_putchar(*str);
			str++;
		}
	}
	return (result);
}

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n < 0)
	{
		result += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		result += ft_putnbr(n / 10);
		result += ft_putchar(n % 10 + '0');
	}
	else
		result += ft_putchar(n + '0');
	return (result);
}

int	hexlen(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static char	*format_check(const char format)
{
	if (format == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

int	ft_print_hex(unsigned long nbr, const char format)
{
	char			*hex;
	int long long	digit;
	int				shift;
	int				zero_check;

	hex = format_check(format);
	shift = (sizeof(nbr) * 8) - 4;
	zero_check = 1;
	while (shift >= 0)
	{
		digit = (nbr >> shift) & 0xf;
		if (digit != 0 || !zero_check)
		{
			if (ft_putchar(hex[digit]) == -1)
				return (-1);
			zero_check = 0;
		}
		shift -= 4;
	}
	if (zero_check)
		if (ft_putchar('0') == -1)
			return (-1);
	return (hexlen(nbr));
}
