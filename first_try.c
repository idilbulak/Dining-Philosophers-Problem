/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_try.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:36:20 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/13 12:55:14 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

pthread_t		philosopher[10];
pthread_mutex_t	chopstick[10];

void	*routine(void *val)
{
	int	n;

	n = (long) val;
	pthread_mutex_lock(&chopstick[n]);
	pthread_mutex_lock(&chopstick[(n + 1) % 10]);
	printf("Philosopher[%d] is eating.\n", n);
	usleep(10000);
	printf("Philosopher[%d] is sleeping.\n", n);
	pthread_mutex_unlock(&chopstick[n]);
	pthread_mutex_unlock(&chopstick[(n + 1) % 10]);
	usleep(10000);
	printf("Philosopher[%d] is thinking.\n", n);
	// usleep(10000);
} 

int	main()
{
	int		i;

	i = 0;
	while ( i < 10)
	{
		pthread_mutex_init(&chopstick[i], NULL);
		i++;
	}
	i = 0;
	while ( i < 10)
	{
		pthread_create(&philosopher[i], NULL, routine, (void *)(long)i);
		i++;
	}
	i = 0;
	while ( i < 10)
	{
		pthread_join(philosopher[i], NULL);
		i++;
	}
	pthread_mutex_destroy(chopstick);
	struct timeval current_time;
  	gettimeofday(&current_time, NULL);
  	printf("seconds : %d\nmicro seconds : %d", current_time.tv_sec, current_time.tv_usec);
}
