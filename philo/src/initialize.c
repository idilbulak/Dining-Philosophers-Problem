/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 10:37:19 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 11:39:21 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_init_mutex(t_philo *p)
{
	int	i;

	i = 0;
	p->mutex = malloc((p->n_philos + 1) * sizeof(pthread_mutex_t));
	if (!p->mutex)
		return (1);
	while (i <= p->n_philos)
	{
		pthread_mutex_init(&p->mutex[i], NULL);
		i++;
	}
	p->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!p->print_mutex)
		return (1);
	pthread_mutex_init(&p->print_mutex[0], NULL);
	return (0);
}

int	ft_initialize(t_philo *p)
{
	p->start_time = gettimeofday_ms(p->start_time) + 1000;
	p->thread = malloc((p->n_philos + 1) * sizeof(pthread_t));
	if (!p->thread)
		return (-1);
	p->is_dead = malloc(sizeof(int));
	p->is_dead[0] = 1;
	if (ft_init_mutex(p))
		return (1);
	return (0);
}
