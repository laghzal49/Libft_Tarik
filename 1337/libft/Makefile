# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 00:37:17 by laaghzal          #+#    #+#              #
#    Updated: 2025/08/25 00:37:18 by laaghzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlen.c ft_tolower.c \
      ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strncmp.c ft_toupper.c \
      ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c \
      ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
      ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
      ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c \
      ft_striteri.c ft_strmapi.c

BONUS_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c \
      ft_lstnew.c ft_lstsize.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
