/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:46:19 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:46:27 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

long	gettimeofday_ms(long time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	time = (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

long	time_check(long time)
{
	long	now;

	now = gettimeofday_ms(now);
	return (now - time);
}
