/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   terminate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:36:59 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:37:01 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_terminate(t_philo *p)
{
	int	i;

	i = 0;
	while (i <= p->n_philos)
	{
		pthread_mutex_destroy(&p->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&p->print_mutex[0]);
	free(p->mutex);
	free(p->print_mutex);
	free(p->thread);
}
