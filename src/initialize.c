/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 13:06:41 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 17:45:22 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	initialize(t_philo *args)
{
	if (init_philo(args) == -1)
	{
		free(args);
		error_input();
		return (-1);
	}
	if (init_mutex(args) == -1)
	{
		free(args);
		error_input();
		return (-1);
	}
	return (1);
}

int	init_philo(t_philo	*philo)
{
	int	i;

	philo = (t_philo *)malloc(sizeof(t_philo) * philo->_philos);
	if (!philo)
		return (-1);
	philo->end_both = 0;
	i = 0;
	while (i < philo->_philos)
	{
		philo[i].id = i + 1;
		philo[i].end = &(philo->end_both);
		philo[i].left_fork = &(philo[i].forks);
		philo[i].right_fork = &(philo[(i + 1) % philo->_philos].forks);
		philo[i]._meals = 0;
		i++;
	}
	return (1);
}

int	init_mutex(t_philo *philo)
{
	unsigned int	i;

	if(pthread_mutex_init(&(philo->print), NULL) != 0)
		// return(-1);
	i = 0;
	while(i < philo->_philos)
	{
		if (pthread_mutex_init(philo[i]->forks, NULL) != 0)
		{
			while(i)
			{
				pthread_mutex_destroy(philo[i].forks);
				i--;
			}
			pthread_mutex_destroy(&(philo->print));
			return(-1);
		}
		// if(pthread_mutex_init(philo[i]->event, NULL) != 0)
		{
			while(i)
			{
				pthread_mutex_destroy(philo[i].forks);
				pthread_mutex_destroy(philo[i].event);
				i--;
			}
			pthread_mutex_destroy(&(philo->print));
			return(-1);
		}
		i++;
	}
	return(1);
}