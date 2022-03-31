# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sumsong <sumsong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 18:37:48 by sumsong           #+#    #+#              #
#    Updated: 2022/03/09 15:28:13 by sumsong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h
SRCS = ft_printf.c ft_printf_format_specifier.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: all clean fclean re bonus