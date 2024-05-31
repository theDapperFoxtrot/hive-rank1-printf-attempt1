/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:33:08 by smishos           #+#    #+#             */
/*   Updated: 2024/05/31 16:33:10 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	ft_printf("\nThis is a number: %d\n", 42);
	printf("\nprintf - This is a number: %d\n", 42);
	ft_printf("\nThis is a string: %s\n", "Hello, World!");
	printf("\nprintf - This is a string: %s\n", "Hello, World!");
	ft_printf("\nThis is a pointer: %p\n", &main);
	printf("\nprintf - This is a pointer: %p\n", &main);
	ft_printf("\nThis is a hex number: %x\n", 42);
	printf("\nprintf - This is a hex number: %x\n", 42);
	ft_printf("\nThis is a hex number: %X\n", 42);
	printf("\nprintf - This is a hex number: %X\n", 42);
	ft_printf("\nThis is a hex number: %x\n", 0);
	printf("\nprintf - This is a hex number: %x\n", 0);
	ft_printf("\nThis is a hex number: %X\n", 0);
	printf("\nprintf - This is a hex number: %X\n", 0);
	return (0);
}