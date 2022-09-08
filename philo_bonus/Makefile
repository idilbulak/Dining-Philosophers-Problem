GREEN = \033[32m
CYAN = \033[0;36m
PURPLE = \033[0;35m
RED = \033[0;31m
WHITE =  \033[0;38m
RESET = \033[0m

NAME			=	philo_bonus

SRCS_DIR		=	./src/

INCLUDES		=	./inc/

SRCS_F			=	philo_bonus.c \
					parser_bonus.c \
					death_monitor_bonus.c \
					initialize_bonus.c \
					simulation_bonus.c \
					terminate_bonus.c \
					time_bonus.c \
					philo_utils_bonus.c \

SRCS			= 	$(addprefix $(SRCS_DIR), $(SRCS_F))

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
CC_FLAGS		= 	-Wall -Wextra -Werror

.c.o:			
				$(CC) $(C_FLAGS) -c $< -o $(<:.c=.o)


$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
				@echo "$(GREEN)*---------------------------------------------------------*$(RESET)"
				@echo "$(GREEN)|                                                         |$(RESET)"
				@echo "$(GREEN)*                    PHILO_BONUS                          *$(RESET)"
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