CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
src/read_file.c
OBJS = $(SRCS:.c=.o)
NAME = nmsound

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

