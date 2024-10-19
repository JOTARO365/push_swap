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

NAME		=	push_swap

OBJ_DIR 	=	src

SRC		=	main.c instruction.c

CC		=	cc

CFLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	libft

LIBFT		=	$(LIBFT_DIR)/libft.a

OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

RM		=	rm -rf


bin/$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME)

all : $(NAME)

clean	:
	$(RM) $(OBJ)
	$(RM) $(LIBFT_DIR)/*.o

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY : all clean fclean re
