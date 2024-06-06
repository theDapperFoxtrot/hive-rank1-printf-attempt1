/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:33:08 by smishos           #+#    #+#             */
/*   Updated: 2024/06/06 11:14:56 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	ft_printf("\nThis is a hex number: %x\n", 9223372036854775807);
	printf("\nprintf - This is a hex number: %lx\n", 9223372036854775807);
	ft_printf("\nThis is a number: %d\n", 42);
	printf("\nprintf - This is a number: %d\n", 42);
	ft_printf("\nThis is a string: %s\n", "Hello, World!");
	printf("\nprintf - This is a string: %s\n", "Hello, World!");
	ft_printf("\nThis is a pointer: %p\n", &main);
	printf("\nprintf - This is a pointer: %p\n", &main);
	ft_printf("\nThis is a hex number: %x\n", 420);
	printf("\nprintf - This is a hex number: %x\n", 420);
	ft_printf("\nThis is a hex number: %X\n", 42);
	printf("\nprintf - This is a hex number: %X\n", 42);
	ft_printf("\nThis is a hex number: %x\n", 0);
	printf("\nprintf - This is a hex number: %x\n", 0);
	ft_printf("\nThis is a hex number: %X\n", 0);
	printf("\nprintf - This is a hex number: %X\n", 0);
	ft_printf("%x \n", 4294967296);
	printf("%x \n\n", 4294967296);
	return (0);
}