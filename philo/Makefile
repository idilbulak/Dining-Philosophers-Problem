GREEN = \033[32m
CYAN = \033[0;36m
PURPLE = \033[0;35m
RED = \033[0;31m
WHITE =  \033[0;38m
RESET = \033[0m

NAME			=	philo

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

SRCS_F			=	philo.c \
					parser.c \
					death_monitor.c \
					initialize.c \
					routine.c \
					terminate.c \
					time.c \
					philo_utils.c \

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror -fsanitize=thread

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)*---------------------------------------------------------*$(RESET)"
				@echo "$(GREEN)| $(WHITE)               ____  _     _  _     ____                $(GREEN)|$(RESET)"
				@echo "$(GREEN)* $(WHITE)              /  __\/ \ /|/ \/ \   /  _ \             $(GREEN)  *$(RESET)"
				@echo "$(GREEN)| $(WHITE)              |  \/|| |_||| || |   | / \|             $(GREEN)  |$(RESET)"
				@echo "$(GREEN)* $(WHITE)              |  __/| | ||| || |_/\| \_/|            $(GREEN)   *$(RESET)"
				@echo "$(GREEN)| $(WHITE)              \_/   \_/ \|\_/\____/\____/           $(GREEN)    |$(RESET)"
				@echo "$(GREEN)*                                                         *$(RESET)"
				@echo "$(GREEN)|                                                         |$(RESET)"
				@echo "$(GREEN)*  $(PURPLE)<n_philos> <time_to_die> <time_to_eat> <time_to_sleep> $(GREEN)*$(RESET)"
				@echo "$(GREEN)|                                                         |$(RESET)"
				@echo "$(GREEN)*---------------------------------------------------------*$(RESET)"  
                


                         
all:			$(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re