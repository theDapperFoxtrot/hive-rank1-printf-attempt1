/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:31:17 by smishos           #+#    #+#             */
/*   Updated: 2024/05/28 16:33:22 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	ft_printf("Hello, World!\n");
	ft_printf("This is a number: %d\n", 42);
	ft_printf("This is a string: %s\n", "Hello, World!");
	ft_printf("This is a pointer: %p\n", &main);
	ft_printf("This is a hex number: %x\n", 42);
	ft_printf("This is a hex number: %X\n", 42);
	ft_printf("This is a hex number: %x\n", 0);
	ft_printf("This is a hex number: %X\n", 0);
	return (0);
}