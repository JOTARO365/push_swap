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

OBJ_DIR 	=	bin

SRC		=	main.c instruction.c

CC		=	cc

CFLAGS		=	-Wall -Wextra -Werror

LIBFT_DIR	=	libft

LIBFT		=	$(LIBFT_DIR)/libft.a

OBJ		=	$(addprefix $(OBJ_DIR)/src/ , $(addsuffix .o, $(SRC)))

RM		=	rm -f


$(OBJ_DIR)/src/%.o: %.c
	@mkdir -p $(OBJ_DIR)/src
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LIBFT) -o $(NAME)

all : $(NAME)

clean	: 
	$(RM) $(FOLDER) $(SRC)
fclean	:
	$(RM) $(NAME)

re :
	make fclean
	make

.PHONY : all clean fclean re
