/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   creating_single_thread.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 10:17:23 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/12 10:09:13 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>

void	*routine(void *ptr)
{
	while (1)
		printf("This is a thread function with argument (%i).\n", *(int *)ptr);
}

int	main(void)
{
	pthread_t	id;
	int			*ptr;
	int			ret;
	int			j;

	j = 2;
	ret = pthread_create(&id, NULL, routine, &j);
	if (ret == 0)
		printf("thread created succesfully\n");
	else
	{
		printf("thread is not created\n");
		return (0);
	}
	// pthread_join(id, (void **)&ptr);
	while (1)
		printf("This is the main function.\n");
}

// void	*routine(void *ptr)
// {
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		printf("This is a thread function with argument (%i).\n", *(int *)ptr);
// 		i++;
// 	}
// 	return 0;
// }

// int	main(void)
// {
// 	pthread_t	id;
// 	int			*ptr;
// 	int			ret;
// 	int			j;

// 	j = 2;
// 	ret = pthread_create(&id, NULL, routine, &j);
// 	if (ret == 0)
// 		printf("thread created succesfully\n");
// 	else
// 	{
// 		printf("thread is not created\n");
// 		return (0);
// 	}
// 	pthread_join(id, (void **)&ptr);
// 	int i = 0;
// 	while (i < 10)
// 	{
// 		printf("This is the main function.\n");
// 		i++;
// 	}
// }

// int	i = 2;
	
// void	*routine(void *ptr)
// {
// 	printf("value recieved as argument in starting routine: %i\n", *(int *)ptr);
// 	pthread_exit(&i);
// }

// int	main(void)
// {
// 	pthread_t	id;
// 	int			*ptr;
// 	int			j;

// 	j = 1;
// 	pthread_create(&id, NULL, routine, &j);
// 	pthread_join(id, (void **)&ptr);
// 	printf("value recevied y parent from child: %i\n", *ptr);
// }

/*
int	pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg); 
int pthread_join(pthread_t thread, void **value_ptr);
gcc creating_single_thread.c -lpthread
*/