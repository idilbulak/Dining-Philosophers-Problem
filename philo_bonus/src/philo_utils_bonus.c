/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_utils_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:45:03 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:45:13 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_print(t_philo *ph, char *color, char *str)
{
	long	time;

	time = gettimeofday_ms(time);
	sem_wait(ph->sem_print);
	sem_wait(ph->sem_isdead);
	printf("%ld\t%s[P%d] %s\n%s",
		time - ph->start_time, color, ph->i, str, RESET);
	sem_post(ph->sem_isdead);
	sem_post(ph->sem_print);
}
