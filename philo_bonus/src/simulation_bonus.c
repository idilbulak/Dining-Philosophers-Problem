/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulation_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:45:56 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:47:03 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	routine(t_philo *ph)
{
	if (ph->i != ph->n_philos)
		sem_wait(ph->sem_last);
	sem_post(ph->sem_last);
	ph->start_time = gettimeofday_ms(ph->start_time);
	ph->time_left = ph->start_time + ph->time_to_die;
	if (ph->i % 2 == 1)
		usleep(1000);
	while (1)
	{
		sem_wait(ph->sem_forks);
		ft_print(ph, CYAN, "has taken a fork");
		usleep(50);
		sem_wait(ph->sem_forks);
		ft_print(ph, CYAN, "has taken a fork");
		ft_eat(ph);
		sem_post(ph->sem_forks);
		sem_post(ph->sem_forks);
		ft_sleep_think(ph);
		if (!ph->meals)
			break ;
	}
	exit (0);
}

void	ft_eat(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(ph, YELLOW, "is eating");
	while (1)
	{
		usleep(200);
		death_monitor(ph);
		if (time_check(time) >= ph->time_to_eat)
			break ;
	}
	time = gettimeofday_ms(time);
	ph->time_left = time + ph->time_to_die;
	ph->meals--;
}

void	ft_sleep_think(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(ph, PURPLE, "is sleeping");
	while (1)
	{
		usleep(200);
		if (time_check(time) >= ph->time_to_sleep)
			break ;
	}
	ft_print(ph, GREEN, "is thinking");
}
