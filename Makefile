# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: waon-in <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 21:05:45 by waon-in           #+#    #+#              #
#    Updated: 2024/04/16 21:14:59 by waon-in          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRC	=	main.c instruction.c

CC	=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f





