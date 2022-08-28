#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>

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
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals; 
	long			start_time;
	pthread_t		*thread;
	int				*is_dead; //malloctan kurtar
	int				i;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print_mutex;
	int				lfork;
	int				rfork;
	long			time_left;
}	t_philo;

//parser
// int			if_correctinput(char **argv);
// int			args_helper(char *argv, long long *nbr);
// void		required_args(char **argv, t_philo *args, long long nbr);
// void		optional_args(char **argv, t_philo *philo, long long nbr);
long	ft_atoi(char *argv);
int	ft_isdigit(char c);
t_philo	parser(int argc, char **argv, t_philo p);
int    ft_initialize(t_philo *p);
void	death_monitor(t_philo *ph);
void    *routine(void   *p);
void	ft_terminate(t_philo *p);
long  time_check(long time);
long	gettimeofday_ms(long time);
void	ft_print(t_philo *ph, char *color, char *str);


#endif