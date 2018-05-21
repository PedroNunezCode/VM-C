NAME = vm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c

all:
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
