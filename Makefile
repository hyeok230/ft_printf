# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junylee <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/04 11:21:37 by junylee           #+#    #+#              #
#    Updated: 2021/08/18 20:34:59 by junylee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
SOURCES		= ft_printf.c\
			  utils.c\
			  ft_itoa.c\
			  ft_parse.c\
			  ft_basic.c\
			  ft_join.c
BONUS		= ft_printf_bonus.c\
			  utils_bonus.c\
			  ft_itoa_bonus.c\
			  ft_parse_bonus.c\
			  ft_basic_bonus.c\
			  ft_join_bonus.c
OBJECTS		= ${SOURCES:.c=.o}
BONUS_OBJECTS = ${BONUS:.c=.o}
RM			= rm -f

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

bonus : ${BONUS_OBJECTS}
	ar rc ${NAME} ${BONUS_OBJECTS}

clean:
	${RM} ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re bonus
