/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex_example.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 13:37:02 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/12 14:14:26 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;

void	*routine(void *ptr)
{
	static int	    change = 0;
	
    pthread_mutex_lock(&lock);
	printf("thread no:%i started with argument (%i).\n", ++change , *(int *)ptr);
    printf("thread is done\n");
    pthread_mutex_unlock(&lock);
    return 0;
}

int main (void)
{
	pthread_t	    id[10];
	int			    i;
	int		    	j;

	i = 0;
	j = 2;
    if (pthread_mutex_init(&lock, NULL) != 0)
        printf("Mutex init hs failed.\n");
	while ( i < 10)
	{
		if ((pthread_create(&id[i], NULL, routine, &j) != 0))
            printf("Thread can't be created.\n");
        else
		    i++;
	}
    i = 0;
    while (i < 10)
    {
        pthread_join(id[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&lock);
	pthread_exit(NULL);
	return 0;
}

/*
int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);
*/