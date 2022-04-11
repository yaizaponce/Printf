# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yponce-p <yponce-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 17:31:12 by yponce-p          #+#    #+#              #
#    Updated: 2022/04/04 17:52:28 by yponce-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = check1.c check2.c check3.c ft_printf.c ft_utoa.c

INCLUDE = ft_printf.h

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
		${MAKE} -C ./Libft all
		cp ./Libft/libft.a ${NAME}
		${AR} ${NAME} ${OBJS}
		${RN} ${NAME}

all:	${NAME}

clean: 
		${MAKE} -C ./Libft clean
		${RM} ${OBJS}

fclean: clean
			${MAKE} -C ./Libft fclean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
