/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:28:44 by smishos           #+#    #+#             */
/*   Updated: 2024/05/29 16:46:54 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int result;

	result = write(1, &c, 1);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_putstr(char *str)
{
	int result;

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
	int result;

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

int	ft_putnbr_base(unsigned int n, char *base)
{
	int result;
	int base_len;

	result = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
	{
		result += ft_putnbr_base(n / base_len, base);
		result += ft_putchar(base[n % base_len]);
	}
	else
		result += ft_putchar(base[n]);
	return (result);
}