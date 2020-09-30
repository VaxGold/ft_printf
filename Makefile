# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omercade <omercade@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 19:01:37 by omercade          #+#    #+#              #
#    Updated: 2020/09/30 19:26:05 by omercade         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBROOT	=	./libft

MAKE	=	make

SRCS    =	ft_printf.c ft_writer1.c ft_writer2.c printftools.c
			
OBJS    =	${SRCS:.c=.o}

INCLUDE	=	ft_printf.h

NAME    =	libftprintf.a 

CC      =	cc

RM      =	rm -f

LIB		=	ar rcs

CFLAGS  =	-Wall -Werror -Wextra

IFLAGS	=	-I$(LIBROOT)

.c.o:	$(INCLUDE)
	${CC} ${CFLAGS} $(IFLAGS) -c $< -o ${<:.c=.o}
$(NAME):   libft_all ${OBJS}
	cp $(LIBROOT)/libft.a $(NAME)
	$(LIB) ${NAME} ${OBJS}

all:      ${NAME}

clean:	libft_clean
		${RM} ${OBJS}

fclean:     libft_fclean clean
		${RM} ${NAME}

re:        libft_fclean fclean all

libft_all:
	$(MAKE) -C $(LIBROOT) all

libft_clean:
	$(MAKE) -C $(LIBROOT) clean

libft_fclean:
	$(MAKE) -C $(LIBROOT) fclean

.PHONY:	clean all fclean re