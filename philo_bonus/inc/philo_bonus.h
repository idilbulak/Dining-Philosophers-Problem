#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define CYAN "\033[0;36m"
# define TEAL "\033[0;36m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int			n_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals;
	long			start_time;
	long			time_left;
	int				*pid;
	int			i;
	sem_t			*sem_forks;	
	sem_t			*sem_print;
	sem_t			*sem_isdead;
	sem_t			*sem_last;
}	t_philo;

t_philo	parser(int argc, char **argv, t_philo ph);
void	ft_initialize(t_philo *ph);
void	ft_terminate(t_philo *ph);
long	time_check(long time);
void	ft_print(t_philo *ph, char *color, char *str);
void	death_monitor(t_philo *ph);
void	ft_eat(t_philo *ph);
void	ft_sleep_think(t_philo *ph);
void	simulation(t_philo *ph);
long	gettimeofday_ms(long time);
int	ft_isdigit(char c);
long	ft_atoi(char *argv);

#endif
