NAME = libft.a
SRC = ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlen.c ft_tolower.c \
      ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strncmp.c ft_toupper.c \
      ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strnstr.c \
      ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_strjoin.c ft_strrchr.c \
      ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c ft_strlcat.c ft_strtrim.c \
      ft_isascii.c ft_memcpy.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
