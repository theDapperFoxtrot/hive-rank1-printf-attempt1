/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:17:50 by smishos           #+#    #+#             */
/*   Updated: 2024/05/28 16:32:14 by smishos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int ft_printf(const char *format, ...);
int ft_putchar(char c);
int ft_puthex(int num);
int ft_putstr(char *str);
int ft_putptr(void *ptr);
int ft_putnbr(int num);

#endif