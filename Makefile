SRC = main.c arg_check.c init.c ft_atoi.c assign.c fork_work.c gogo_work.c time.c party.c dest.c manage_death.c print_status.c ft_free.c check_init.c

OBJ = ${SRC:.c=.o}

NAME = philo

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread -g3

RM = rm -f

all :
	${CC} ${FLAGS} -o ${NAME} ${SRC}

clean : 
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
