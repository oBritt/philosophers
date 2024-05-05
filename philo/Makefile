CFLAGS = -Wall -Wextra -Werror -pthread

SRCS = filo.c main.c mutexes.c only1philo.c prints.c time.c utils.c validate.c init_super.c waiting_for_all_threads.c \
init_send.c init_forks.c loop.c actions.c check_if_dead.c a_sleeping.c a_eat.c

OBJS = $(SRCS:.c=.o)

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re