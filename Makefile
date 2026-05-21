# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wiaon-in <wiaon-in@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/21 00:00:00 by wiaon-in          #+#    #+#              #
#    Updated: 2026/05/21 00:00:00 by wiaon-in         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INC			= -I. -I$(LIBFT_DIR)

SRCS		= main.c parse.c validate.c stack.c normalize.c \
			  ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c \
			  utils.c sort_small.c sort_large.c cost.c move.c
OBJS		= $(SRCS:.c=.o)

SRCS_B		= checker_bonus.c parse.c validate.c stack.c normalize.c \
			  ops_swap.c ops_push.c ops_rotate.c ops_rrotate.c \
			  utils.c sort_small.c sort_large.c cost.c move.c
OBJS_B		= $(SRCS_B:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $@ $^ $(LIBFT)

bonus: $(LIBFT) $(OBJS_B)
	$(CC) $(CFLAGS) $(INC) -o $(BONUS_NAME) $(OBJS_B) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

norm:
	python3 -m norminette *.c *.h

clean:
	rm -f $(OBJS) $(OBJS_B)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus norm
