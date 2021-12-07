# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 10:31:04 by lmaujean          #+#    #+#              #
#    Updated: 2021/11/30 10:31:05 by lmaujean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC= gcc

CFLAGS= -Wall -Wextra -Werror  #-g -fsanitize=address

RM= rm -f

MLX= -lmlx -framework OpenGL -framework AppKit

SRC =	./srcs/main.c\
		./srcs/utils.c\
		./srcs/utils2.c\
		./srcs/pars.c\
		./srcs/init.c\
		./srcs/GNL_utils.c\
		./srcs/GNL.c\
		./srcs/map.c\
		./srcs/stock.c\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)
			
reset: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re reset