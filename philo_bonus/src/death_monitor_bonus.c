/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   death_monitor_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:39:52 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:40:13 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	death_monitor(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	if (time - ph->time_left > 0)
	{
		sem_wait(ph->sem_isdead);
		printf("%s%ld\t[P%d] died\n", \
				RED, time - ph->start_time, ph->i);
		exit(1);
	}
}
