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

typedef struct s_philo
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals; 
	long			start_time;
	int				*is_dead; //malloctan kurtar
	pthread_t		*id;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print_mutex;
	int				i;
	int				lfork;
	int				rfork;
	long			time_left;
}	t_philo;


// parser
int			if_correctinput(char **argv);
int			args_helper(char *argv, long long *nbr);
void		required_args(char **argv, t_philo *args, long long nbr);
void		optional_args(char **argv, t_philo *philo, long long nbr);
int			parser(int argc, char **argv, t_philo *philo);

// initilization
long		gettimeofday_ms(long now);
int			initialize(t_philo *philo);

// tasks
static int	ft_eat(t_philo *philo);
static void	ft_sleep_think(t_philo *philo);
void		ft_tasks(t_philo *philo);
bool		death_monitor(t_philo *philo);
void		ft_print(t_philo *philo, char *str);

// simulation
int			simulation(t_philo philo);
long		check_time(long start_time);
void		assign_forks(t_philo *philo);
void		*routine(void *philo);

// utils
int	ft_isdigit(char c);
int	ft_strlen(const char *s);
static int	ft_isspace(char c);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif