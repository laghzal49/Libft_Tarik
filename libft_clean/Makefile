# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 19:20:29 by laaghzal          #+#    #+#              #
#    Updated: 2025/08/25 01:09:34 by laaghzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlen.c ft_tolower.c \
      ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strncmp.c ft_toupper.c \
      ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c \
      ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
      ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
      ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
      ft_striteri.c ft_strmapi.c

SRCSB = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
      ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstclear_bonus.c \
      ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJS) $(OBJSB)
	ar rcs $(NAME) $(OBJS) $(OBJSB)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all
