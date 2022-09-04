RESET = \033[0m
GREEN = \033[32m
CYAN = \033[0;36m
PURPLE = \033[0;35m
RED = \033[0;31m
WHITE =  \033[0;38m

NAME			=	philo_bonus

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

AR				=	ar
ARFLAGS			=	rcs

SRCS_F			=	philo_bonus.c philo_utils_bonus.c parser_bonus.c initialize_bonus.c \
					simulation_bonus.c death_monitor_bonus.c terminate_bonus.c time_bonus.c

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)*-----------------------------------------------------------------------*$(RESET)"
				@echo "$(GREEN)| $(WHITE)     ____  _     _  _     ____       ____  ____  _      _     ____    $(GREEN)|$(RESET)"
				@echo "$(GREEN)* $(WHITE)    /  __\/ \ /|/ \/ \   /  _ \     /  _ \/  _ \/ \  /|/ \ /\/ ___\   $(GREEN)*$(RESET)"
				@echo "$(GREEN)| $(WHITE)    |  \/|| |_||| || |   | / \|     | | //| / \|| |\ ||| | |||    \   $(GREEN)|$(RESET)"
				@echo "$(GREEN)* $(WHITE)    |  __/| | ||| || |_/\| \_/|     | |_\\| \_/|| | \||| \_/|\___  |   $(GREEN)*$(RESET)"
				@echo "$(GREEN)| $(WHITE)    \_/   \_/ \|\_/\____/\____/_____\____/\____/\_/  \|\____/\____/   $(GREEN)|$(RESET)"
				@echo "$(GREEN)*                                                                       *$(RESET)"
				@echo "$(GREEN)|                                                                       |$(RESET)"
				@echo "$(GREEN)*        $(PURPLE)<n_philos> <time_to_die> <time_to_eat> <time_to_sleep>         $(GREEN)*$(RESET)"
				@echo "$(GREEN)|                                                                       |$(RESET)"
				@echo "$(GREEN)*-----------------------------------------------------------------------*$(RESET)"  





                                                        

all:			$(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re