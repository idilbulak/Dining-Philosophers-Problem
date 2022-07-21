GREEN = \033[32m
BLUE = \033[34m
YELLOW = \e[0;33m
RESET = \033[0m

NAME			=	philo

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	philo.c philo_utils.c parser.c initialize.c \
					simulation.c tasks.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -lpthread

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)Philosophers are starving!$(RESET)"

all:			$(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re