/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   death_monitor.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 10:37:06 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:24:26 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	death_monitor(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	if (time - ph->time_left > 0)
	{
		pthread_mutex_lock(&ph->print_mutex[0]);
		if (ph->is_dead[0])
			printf("%s%ld\t[P%d] died\n", \
				RED, time - ph->start_time, ph->i);
		ph->is_dead[0] = 0;
		pthread_mutex_unlock(&ph->print_mutex[0]);
	}
}
