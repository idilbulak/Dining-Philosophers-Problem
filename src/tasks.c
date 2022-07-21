#include "../inc/philo.h"

void	ft_print(t_philo *philo, char *str)
{
	long	time;

	time = gettimeofday_ms(time);
	pthread_mutex_lock (&philo->print_mutex[0]);
	if (philo->is_dead[0])
		printf("%ld %d %s\n", time - philo->start_time, philo->i, str);
	pthread_mutex_unlock (&philo->print_mutex[0]);
}

void	death_monitor(t_philo *philo)
{
	long	time;

	time = gettimeofday_ms(time);
	if (time - philo->time_left > 0)
	{
		pthread_mutex_lock (&philo->print_mutex[0]);
		if (philo->is_dead[0])
		{
			printf("%ld %d died\n", time - philo->start_time, philo->i);
		}
		philo->is_dead[0] = 0;
		pthread_mutex_unlock (&philo->print_mutex[0]);
	}
}

static void	ft_eat(t_philo *philo)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(philo, "is eating");
	while (1)
	{
		usleep(1000);
		death_monitor(philo);
		if (check_time(time) >= philo->time_to_eat)
			break ;
	}
	time = gettimeofday_ms(time);
	philo->time_left = time + philo->time_to_die;
	philo->meals--;
}

static void	ft_sleep_think(t_philo *philo)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(philo, "is sleeping");
	while (1)
	{
		usleep (1000);
		if (check_time(time) >= philo->time_to_sleep)
			break ;
	}
	ft_print(philo, "is thinking");
}

void	ft_tasks(t_philo *philo)
{
	if (philo->n_philos % 2 == 1)
		usleep(1000);
	while (philo->is_dead[0])
	{
		
		pthread_mutex_lock(&philo->mutex[philo->rfork]);
		ft_print(philo, "has taken a fork");
		usleep (1000);
		pthread_mutex_lock(&philo->mutex[philo->lfork]);
		ft_print(philo, "has taken a fork");
		ft_eat(philo);
		pthread_mutex_unlock(&philo->mutex[philo->lfork]);
		pthread_mutex_unlock(&philo->mutex[philo->rfork]);
		ft_sleep_think(philo);
		if (philo->meals <= 0)
			break ;
	}
}