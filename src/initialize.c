#include "../inc/philo.h"

long	gettimeofday_ms(long time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	time= (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

int	initialize(t_philo	*philo)
{
	int	i;

	i = 0;
	philo->start_time = gettimeofday_ms(philo->start_time) + 1000;
	philo->id = malloc((philo->n_philos + 1) * sizeof(pthread_t));
	if (!philo->id)
		return (-1);
	philo->is_dead = malloc(sizeof(int));
	philo->is_dead[0] = 1;
	philo->i = 1;
	philo->mutex = malloc((philo->n_philos + 1) * sizeof(pthread_mutex_t));
	if (!philo->mutex)
		return (-1);
	while (i <= philo->n_philos)
	{
		pthread_mutex_init(&philo->mutex[i], NULL);
		i++;
	}
	philo->print_mutex = malloc(sizeof(pthread_mutex_t));
	if (!philo->print_mutex)
		return (-1);
	pthread_mutex_init(&philo->print_mutex[0], NULL);
	return (1);
}

