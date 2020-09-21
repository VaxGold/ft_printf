# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omercade <omercade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:01:37 by omercade          #+#    #+#              #
#    Updated: 2020/09/17 17:54:10 by omercade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =	ft_printf.c/
			
OBJS    = ${SRCS:.c=.o}

NAME    = ft_printf.a

CC      = cc

RM      = rm -f

CFLAGS  = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
$(NAME):    ${OBJS}
	ar rc  ${NAME} ${OBJS}
	ranlib ${NAME}

all:       ${NAME}

clean:
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:     clean
		${RM} ${NAME}

re:         fclean

.PHONY:	clean all fclean re