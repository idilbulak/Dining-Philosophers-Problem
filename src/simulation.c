#include "../inc/philo.h"

long	check_time(long start_time)
{
	long			time;

	time = gettimeofday_ms(time);
	return (time - start_time);
}

void	assign_forks(t_philo *philo)
{
	philo->lfork = philo->i;
	if (philo->i == philo->n_philos)
		philo->rfork = 1;
	else
		philo->rfork = philo->i + 1;
}

void	*routine(void *philo)
{
	t_philo			_philo;


	_philo = *(t_philo *) philo;
	assign_forks(&_philo);
	while (1)
	{
		if (check_time(_philo.start_time) >= 1000)
			break ;
		usleep (1000);
	}
	_philo.start_time = gettimeofday_ms(_philo.start_time);
	_philo.time_left = _philo.start_time + _philo.time_to_die;
	ft_tasks(&_philo);
}

int	simulation(t_philo philo)
{
	while (philo.i <= philo.n_philos)
	{
		pthread_create(&philo.id[philo.i], NULL, routine, &philo);
		usleep(1000);
		philo.i++;
	}
	philo.i = 1;
	while (philo.i <= philo.n_philos)
	{
		pthread_join(philo.id[philo.i], NULL);
		philo.i++;
	}
	return (1);
}