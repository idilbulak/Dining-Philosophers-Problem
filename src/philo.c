#include "../inc/philo.h"

void	destroy_mutex(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->n_philos >= 0)
	{
		pthread_mutex_destroy(&philo->mutex[i]);
		i--;
	}
	free (philo->mutex);
	pthread_mutex_destroy(&philo->print_mutex[0]);
	free(philo->print_mutex);
}

void	ft_terminate(t_philo *philo)
{
	free(philo->id);
	free(philo->is_dead);
	free(philo);
}

int	main (int argc, char** argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (-1);
	if(parser(argc, argv, philo) == -1)
		return(-1);
	if (philo->n_philos == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(philo->time_left * 1000);
		printf("%lu 1 died\n", philo->time_left);
		return (-1);
	}
	if(initialize(philo) == -1)
		return(-1);
	if(simulation(*philo) == -1)
		return (-1);
	destroy_mutex(philo);
	ft_terminate(philo);
	return (1);	
}