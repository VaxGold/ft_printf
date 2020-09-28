# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omercade <omercade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:01:37 by omercade          #+#    #+#              #
#    Updated: 2020/09/28 19:42:23 by omercade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =	ft_printf.c ft_writer1.c ft_writer2.c printftools.c
			
OBJS    = ${SRCS:.c=.o}

NAME    = libftprintf.a 

CC      = cc

RM      = rm -f

CFLAGS  = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME):    ${OBJS}
	ar rcs  ${NAME} ${OBJS}

all:       ${NAME}

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:     clean
		${RM} ${NAME}

re:         fclean all

.PHONY:	clean all fclean re