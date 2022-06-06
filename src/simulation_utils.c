#include "../inc/philo.h"

static void	take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "has taken a fork");
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "has taken a fork");
	pthread_mutex_unlock(philo->print);
}

static void	take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "has taken a fork");
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "has taken a fork");
	pthread_mutex_unlock(philo->print);
}

static int	ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		take_left_fork(philo);
	else
		take_right_fork(philo);
	pthread_mutex_lock(&(philo->event));
	philo->last_eat = gettimeofday_ms();
	pthread_mutex_unlock(&(philo->event));
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "is eating");
	pthread_mutex_unlock(philo->print);
	usleep_ms(philo->_time_to_eat);
	pthread_mutex_lock(&(philo->event));
	philo->_meals += 1;
	pthread_mutex_unlock(&(philo->event));
	philo_release_forks(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (if_simulation_end(philo));
}

static int	ft_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "is sleeping");
	pthread_mutex_unlock(philo->print);
	usleep_ms(philo->_time_to_sleep);
	return (if_simulation_end(philo));
}

static int	ft_philo_think(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (!(*(philo->end)))
		printf("%llu %u %s\n", gettimeofday_ms() - \
				philo->start, philo->id, "is thinking");
	pthread_mutex_unlock(philo->print);
	usleep(1000);
	return (if_simulation_end(philo));
}



