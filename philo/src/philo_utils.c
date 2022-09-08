/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:39:39 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/06 12:24:21 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

t_philo	assign_forks(t_philo ph)
{
	ph.lfork = ph.i;
	ph.rfork = ph.i + 1;
	if (ph.i == ph.n_philos)
		ph.rfork = 1;
	return (ph);
}

void	ft_print(t_philo *ph, char *color, char *str)
{
	long	time;

	time = gettimeofday_ms(time);
	pthread_mutex_lock (&ph->print_mutex[0]);
	if (ph->is_dead[0])
		printf("%ld\t%s[P%d] %s\n%s",
			time - ph->start_time, color, ph->i, str, RESET);
	pthread_mutex_unlock (&ph->print_mutex[0]);
}
