/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   first_try.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 16:36:20 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/12 17:06:51 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_t		philosopher[10];
pthread_mutex_t	chopstick[10];

void	*routine(void *val)
{
	int	n;

	n = (long) val;
	printf("Philosopher[%d] is thinking.\n", n);
	pthread_mutex_lock(&chopstick[n]);
	pthread_mutex_lock(&chopstick[(n + 1) % 10]);
	printf("Philosopher[%d] is eating.\n", n);
	pthread_mutex_unlock(&chopstick[n]);
	pthread_mutex_unlock(&chopstick[(n + 1) % 10]);
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
}
