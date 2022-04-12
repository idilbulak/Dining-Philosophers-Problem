/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creating_multiple_threads.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 09:38:53 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/12 10:24:03 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

void	*routine(void *ptr)
{
	static int	change = 0;
	
	// while (1)
	{
		printf("This is thread no:%i function with argument (%i).\n", ++change , *(int *)ptr);
		// change++;
	}
}

int main (void)
{
	pthread_t	id;
	int			i;
	int			j;

	i = 0;
	j = 2;
	while ( i <= 10)
	{
		pthread_create(&id, NULL, routine, &j);
		i++;
	}
	pthread_exit(NULL);
	return 0;
}
