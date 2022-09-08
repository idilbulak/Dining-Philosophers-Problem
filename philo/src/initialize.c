/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 10:37:19 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/06 12:26:42 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_init_mutex(t_philo *ph)
{
	int	i;

	i = 0;
	ph->mutex = malloc((ph->n_philos + 1) * sizeof(pthread_mutex_t));
	if (!ph->mutex)
		return (1);
	while (i <= ph->n_philos)
	{
		pthread_mutex_init(&ph->mutex[i], NULL);
		i++;
	}
	ph->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!ph->print_mutex)
		return (1);
	pthread_mutex_init(&ph->print_mutex[0], NULL);
	return (0);
}

int	ft_initialize(t_philo *ph)
{
	ph->start_time = gettimeofday_ms(ph->start_time) + 1000;
	ph->thread = malloc((ph->n_philos + 1) * sizeof(pthread_t));
	if (!ph->thread)
		return (-1);
	ph->is_dead = malloc(sizeof(int));
	if (!ph->is_dead)
		return (-1);
	ph->is_dead[0] = 1;
	if (ft_init_mutex(ph))
		return (1);
	return (0);
}
