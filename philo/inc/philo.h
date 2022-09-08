/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:28:39 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/06 12:25:58 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define CYAN "\033[0;36m"
# define TEAL "\033[0;36m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[0;33m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define BRED "\033[1;31m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals;
	long			start_time;
	long			time_left;
	pthread_t		*thread;
	int				*is_dead;
	int				i;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*print_mutex;
	int				lfork;
	int				rfork;
}	t_philo;

//parser
int		invalid_input(int i, char **argv);
long	ft_atoi(char *argv);
int		ft_isdigit(char c);
t_philo	parser(int argc, char **argv, t_philo ph);

//initialize
int		ft_initialize(t_philo *p);
int		ft_init_mutex(t_philo *p);

//death monitor
void	death_monitor(t_philo *ph);

//simulation
void	simulation(t_philo ph);
void	*routine(void *p);
void	ft_tasks(t_philo ph);
void	ft_eat(t_philo *ph);
void	ft_sleep_think(t_philo *ph);

//utils
t_philo	assign_forks(t_philo ph);
void	ft_print(t_philo *ph, char *color, char *str);

//terminate
void	ft_terminate(t_philo *p);

//time
long	gettimeofday_ms(long time);
long	time_check(long time);

#endif