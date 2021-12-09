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

#############################################################################
#							BASIC DECLARATION								#
#############################################################################
NAME			= so_long
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

#############################################################################
#							HEADER DECLARATION								#
#############################################################################
FOLDER_HDR		= includes/

HEADER_SRC		= so_long.h
HEADER_BNS		= so_long_bonus.h

#############################################################################
#							SOURCES DECLARATION								#
#############################################################################
FOLDER			= srcs/
FOLDER_COM		= srcs_com/
FOLDER_BNS		= srcs_bonus/

SRCS			= 	main.c\
					init.c\
					map.c\
					pars.c\
					img.c\
					event.c\
					

SRCS_COM		= 	GNL_utils.c\
					GNL.c\
					utils.c\
					utils2.c\

SRCS_BNS		= main_bonus.c

#############################################################################
#					ADDING PATH VALUES TO SOURCES FILES						#
#############################################################################
SRC				= $(addprefix ${FOLDER}, ${SRCS})
SRC_COM			= $(addprefix ${FOLDER_COM}, ${SRCS_COM})
SRC_BNS			= $(addprefix ${FOLDER_BNS}, ${SRCS_BNS})

OBJS			= ${SRC:.c=.o}
OBJS_COM		= ${SRC_COM:.c=.o}
OBJS_BNS		= ${SRC_BNS:.c=.o}

#############################################################################
#				CHOOSE OF FILES FOR MAC or LINUX							#
#############################################################################
OS				= $(shell uname -s)

ifeq ($(OS),Darwin)
LIB				= -lmlx -framework OpenGL -framework AppKit ./mlx_utils/mlx_utils.a
endif
ifeq ($(OS),Linux)
LIB				= ./mlx_linux/libmlx.a -lXext -lX11 ./mlx_utils/mlx_utils.a
COMPIL_MLX		= make -C ./mlx_linux
CLEAN			= clean
endif
ifdef BONUS
OBJ				= ${OBJS_BNS} ${OBJS_COM}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC}) \
					$(addprefix ${FOLDER_HDR}, ${HEADER_BNS})
else
OBJ				= ${OBJS} ${OBJS_COM}
HEADER			= $(addprefix ${FOLDER_HDR}, ${HEADER_SRC})
endif

#############################################################################
#							DEBUG DECLARATION								#
#############################################################################
ifdef DEBUG
DFLAGS			= -g -fsanitize=address
endif

#############################################################################
#								BASIC 42 RULES								#
#############################################################################

%.o: %.c	${HEADER}
			@${CC} ${DFLAGS} ${CFLAGS} -c -o $@ $<

${NAME}:	${OBJ}
			${COMPIL_MLX}
			@printf "$(GREEN)Creating ${NAME} executable\n$(RES)"
			@${CC} ${DFLAGS} ${CFLAGS} ${OBJ} ${LIB} -o ${NAME}

all:		${NAME}

clean:
			@printf "$(RED)Destroying ${NAME} objs (*.o)\n$(RES)"
			@${RM} ${OBJS} ${OBJS_BNS} ${OBJS_COM}
			@${COMPIL_MLX} ${CLEAN}

fclean:		clean
			@printf "$(RED)Destroying ${NAME} executable\n$(RES)"
			@${RM} ${NAME}

re:			fclean all

bonus:
			@${MAKE} --no-print-directory BONUS=1

#############################################################################
#								CUSTOM RULES								#
#############################################################################
debug:		clean
			@printf "$(BLUE)Added Debug Flags !\n$(RES)"
			@${MAKE} -s --no-print-directory DEBUG=1
			@${MAKE} -s --no-print-directory clean
			@printf "$(BLUE)Next make wil recompile without debug flags :)\n$(RES)"

norm:
			norminette includes/ srcs/ srcs_com/ srcs_bonus/

.PHONY:		all clean fclean re bonus norm debug

#############################################################################
#								COLOR SET									#
#############################################################################
RES			= \e[0m
RED			= \e[1;31m
GREEN		= \e[1;32m
BLUE		= \e[1;34m