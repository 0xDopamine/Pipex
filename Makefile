#_*_ Makefile _*_

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = pipex.c main.c helpers.c helpers2.c helpers3.c

BSRCS = pipex_bonus/main_bonus.c \
	pipex_bonus/pipex_bonus.c \
	pipex_bonus/helpers_bonus.c \
	pipex_bonus/helpers2_bonus.c \
	pipex_bonus/get_next_line_bonus.c \
	pipex_bonus/get_next_line_utils_bonus.c

NAME = mandatory.a

BONUS = bonus.a

OBJS = ${SRCS:.c=.o}

BOBJS = ${BSRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	rm -f $(BONUS)
	ar rc $(NAME) $(OBJS)
	$(CC) $(CFLAGS) $(NAME) -o pipex

re: fclean all

clean:
	rm -f $(NAME)
	rm -f $(BONUS)
	rm -f *.o
	rm -f pipex_bonus/*.o 

fclean:	clean
	rm -f pipex

bonus: $(BONUS)

$(BONUS): $(BOBJS)
	rm -f $(NAME)
	ar rc $(BONUS) $(BOBJS)
	$(CC) $(CFLAGS) $(BONUS) -o pipex

.PHONY: clean fclean bonus re all