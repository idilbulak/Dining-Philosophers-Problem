/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:39:04 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/06 15:09:22 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

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
	int			n_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals;
	long		start_time;
	long		time_left;
	int			*pid;
	int			i;
	sem_t		*sem_forks;	
	sem_t		*sem_print;
	sem_t		*sem_isdead;
	sem_t		*sem_last;
}	t_philo;

//parser
int		invalid_input(int i, char **argv);
long	ft_atoi(char *argv);
int		ft_isdigit(char c);
t_philo	parser(int argc, char **argv, t_philo ph);

//initialize
void	ft_initialize(t_philo *ph);

//death monitor
void	death_monitor(t_philo *ph);

//simulation
void	ft_eat(t_philo *ph);
void	ft_sleep_think(t_philo *ph);
void	routine(t_philo *ph);
void	ft_kill(t_philo ph);
void	simulation(t_philo ph);

//utils
void	ft_print(t_philo *ph, char *color, char *str);

//terminate
void	ft_terminate(t_philo *p);

//time
long	gettimeofday_ms(long time);
long	time_check(long time);

#endif
