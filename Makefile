CC = gcc
NAME = cells
SOURCES = sources/*.c
HEADERS = headers

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)


$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -I $(HEADERS) -o $(NAME)


fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re