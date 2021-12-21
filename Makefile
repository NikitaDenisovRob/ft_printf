# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsato <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:31:08 by jsato             #+#    #+#              #
#    Updated: 2021/12/19 21:24:36 by jsato            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c sources/ft_get_hex.c sources/ft_dec_to_hex.c sources/ft_print_hex.c sources/ft_putchr.c \
			sources/ft_putstr.c sources/ft_get_len.c sources/ft_print_itoa.c sources/ft_print_unsigned_itoa.c 

OBJS			= $(SRCS:.c=.o)


HEADER			= ft_printf.h

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)


clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)


re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
