#_*_ Makefile _*_

CC = cc
CFLAGS =  -c -Wall -Werror -Wextra
SRCS = pipex.c helpers.c helpers2.c
NAME = pipex
OBJS = ${SRCS:.c=.o}

all: $(NAME)

re: fclean all

$(NAME): $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $<
	ar rcs $(NAME) $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean re all