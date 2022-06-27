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
	int		_philos;
	int		_time_to_die;
	int		_time_to_eat;
	int		_time_to_sleep;
	int		_meals;
	int		option;
	int		id;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*event;
	int				start;
	// int				last_eat;
	pthread_t		philo;	
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	char			*end;
	char			end_both;

}	t_philo;

int		get_args_helper(char *argv, long long *nbr);
void	required_args(char **argv, t_philo *args, long long nbr);
void	optional_args(char **argv, t_philo *args, long long nbr);
int		get_args(int argc, char **argv, t_philo *args);

int		init_philo(t_philo	*philo);
int		init_mutex(t_philo *philo);

unsigned long long	gettimeofday_ms(void);
void	usleep_ms(unsigned long long t);
int	if_simulation_end(t_philo *philo);
void	*philo_routine(void *philo);
int	simulation(t_philo *philo);


static void	take_left_fork(t_philo *philo);
static void	take_right_fork(t_philo *philo);
static int	ft_eat(t_philo *philo);
static int	ft_sleep(t_philo *philo);
static int	ft_think(t_philo *philo);

int		checker(t_philo *philo, int philo_dies, int i);
void	*death_monitor(void *_philo);

int	ft_isdigit(char c);
int	ft_strlen(const char *s);
static int	ft_isspace(char c);
int	ft_atoi(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif