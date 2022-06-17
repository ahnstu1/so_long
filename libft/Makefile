# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hahn <hahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 16:30:03 by hahn              #+#    #+#              #
#    Updated: 2021/12/13 04:57:44 by hahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
OBJS = ft_isascii.o\
		ft_memcpy.o\
		ft_split.o\
		ft_strlcpy.o\
		ft_strtrim.o\
		ft_atoi.o\
		ft_isdigit.o\
		ft_memmove.o\
		ft_strchr.o\
		ft_strlen.o\
		ft_substr.o\
		ft_bzero.o\
		ft_isprint.o\
		ft_memset.o\
		ft_strdup.o\
		ft_strmapi.o\
		ft_tolower.o\
		ft_calloc.o\
		ft_itoa.o\
		ft_putendl_fd.o\
		ft_striteri.o\
		ft_strncmp.o\
		ft_toupper.o\
		ft_isalnum.o\
		ft_memchr.o\
		ft_putnbr_fd.o\
		ft_strjoin.o\
		ft_strnstr.o\
		ft_isalpha.o\
		ft_memcmp.o\
		ft_putstr_fd.o\
		ft_strlcat.o\
		ft_strrchr.o\
		ft_putchar_fd.o

BONUS_OBJS = ft_lstnew.o\
		ft_lstadd_front.o\
		ft_lstsize.o\
		ft_lstlast.o\
		ft_lstadd_back.o\
		ft_lstdelone.o\
		ft_lstclear.o\
		ft_lstiter.o\
		ft_lstmap.o

ifdef BONUS_CHECK
	USE_OBJS = $(OBJS) $(BONUS_OBJS)
else
	USE_OBJS = $(OBJS)
endif

all: $(NAME)

$(NAME): $(USE_OBJS)
	ar -curs $@ $^

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	make BONUS_CHECK=1 all

.PHONY: bonus all clean fclean re
