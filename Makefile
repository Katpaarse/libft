
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

CFILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
ft_strlcat.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_atoll.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_putstr.c ft_putnbr.c ft_puthexa.c ft_putadress.c get_next_line.c \
ft_lstnew.c ft_lstadd_front.c ft_listsize ft_lstlast.c ft_lstadd_back ft_lstdelone.c ft_lstclear.c ft_lstiter.c

OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re