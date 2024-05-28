# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smishos <smishos@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 13:26:45 by smishos           #+#    #+#              #
#    Updated: 2024/05/28 12:10:50 by smishos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libftprintf.a
	

libftprintf.a:
	@make -C libft
	@cp libft/libft.a libftprintf.a
	@ar rc libftprintf.a *.o
	@ranlib libftprintf.a