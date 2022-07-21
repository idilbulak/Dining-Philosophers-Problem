#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>
#include <signal.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_philo
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals; 
	int     		*id;
	long			start_time;
	int				i;
	long			time_left;
    sem_t           *sem;
    sem_t           *print_sem;
    sem_t           *death;
    sem_t           *start;
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

// // tasks
static void	ft_eat(t_philo *philo);
static void	ft_sleep_think(t_philo *philo);
void		ft_tasks(t_philo *philo);
void		death_monitor(t_philo *philo);
void		ft_print(t_philo *philo, char *str);

// // simulation
long	check_time(long start_time);
int			simulation(t_philo philo);
void		*routine(t_philo *philo);

// utils
int	ft_isdigit(char c);
int	ft_strlen(const char *s);
static int	ft_isspace(char c);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif