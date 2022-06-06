#include "../inc/philo.h"

unsigned long long	gettimeofday_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	usleep_ms(unsigned long long t)
{
	unsigned long long	start;

	start = gettimeofday_ms();
	while (gettimeofday_ms() - start <= t)
		usleep(1000);
}

int	if_simulation_end(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(philo->print);
	result = *(philo->end);
	pthread_mutex_unlock(philo->print);
	return (result);
}

void	*philo_routine(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (ft_eat(philo))
			return (NULL);
		if (ft_sleep(philo))
			return (NULL);
		if (ft_think(philo))
			return (NULL);
	}
}

int	simulation(t_philo *philo)
{
	unsigned int		i;
	unsigned long long	beginning;
	pthread_t			watcher;			

	i = 0;
	while (i < philo->_philos)
	{
		beginning = gettimeofday_ms();
		philo[i].start = beginning;
		philo[i].last_eat = beginning;
		if(pthread_create(&(philo[i].philo), NULL, philo_routine, &philo[i]) != 0)
		{
			pthread_mutex_lock(philo->print);
			philo->end_both = 1;
			pthread_mutex_unlock(philo->print);
	// 		pthread_join(*observer, NULL);
	// while (i--)
	// 	pthread_join(philo_arg[i].philo, NULL);
	// 		return(-1);
		}
		i++;
	}
	if(pthread_create(&watcher, NULL, death_monitor, philo))
		return(if_simulation_end(philo));
	if (watcher != NULL)
		pthread_join(watcher, NULL);
	while (i--)
		pthread_join(philo[i]._philos, NULL);
	return (1);
}