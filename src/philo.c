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
	if(parser(argc, argv, philo) == -1)
		return(-1);
	if(initialize(philo) == -1)
		return(-1);
	if(simulation(philo) == -1)
		return (-1);
	destroy_mutex(philo);
	ft_terminate(philo);
	return (1);	
}