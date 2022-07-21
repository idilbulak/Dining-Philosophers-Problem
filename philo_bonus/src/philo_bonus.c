#include "../inc/philo_bonus.h"

void	ft_terminate(t_philo *philo)
{
	free(philo->id);
	sem_unlink("/sem");
	sem_unlink("/print_sem");
	sem_unlink("/death");
	sem_unlink("/start");
	sem_close(philo->sem);
	sem_close(philo->print_sem);
	sem_close(philo->death);
	sem_close(philo->start);
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
	ft_terminate(philo);
	return (1);	
}