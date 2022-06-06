#include "../inc/philo.h"

int		checker(t_philo *philo, int philo_dies, int i)
{
	if (philo_dies)
	{
		pthread_mutex_lock((philo + i)->print);
		printf("%llu %u died\n", gettimeoftheday_ms() - (philo + i)->start, (philo + i)->id);
		*((philo + i)->end) = 1;
		philo_release_forks(philo + i);
		pthread_mutex_unlock((philo + i)->print);
	}
	else if (philo->option)
	{
		pthread_mutex_lock(&(philo->print));
		philo->end = 1;
		pthread_mutex_unlock(&(philo->print));
	}
	return (philo_dies || philo->option);
}

void	*death_monitor(void *_philo)
{
	t_philo	*philo;
	int		i;
	int		philo_dies;

	philo = (t_philo *)_philo;
	while (1)
	{
		i = 0;
		while (i < philo->_philos)
		{
			pthread_mutex_lock(&(philo[i].event));
			philo->option &= (philo->_meals <= philo[i]._meals);
			philo_dies = (gettimeoftheday_ms() - philo[i].last_eat > philo->_time_to_die);
			thread_mutex_unlock(&(philo[i].event));
			if (philo_dies)
				break ;
			i++;
		}
		if(checker(philo, philo_dies, i))
		{
			pthread_mutex_lock(&(philo->print));
			philo->end = 1;
			pthread_mutex_unlock(&(philo->print));
		}
		usleep(1000);
	}
}