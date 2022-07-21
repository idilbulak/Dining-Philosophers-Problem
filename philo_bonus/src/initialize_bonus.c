#include "../inc/philo_bonus.h"

long	gettimeofday_ms(long time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	time= (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

int initialize(t_philo *philo)
{
	philo->i = 1;
	philo->id = malloc((philo->n_philos + 1) * sizeof(int));
	if (!philo->id)
		return (-1);
	memset(philo->id, 0, philo->n_philos + 1);
	sem_unlink("/sem");
	sem_unlink("/print_sem");
	sem_unlink("/death");
	philo->sem = sem_open("/forks", O_CREAT, 0644, philo->n_philos);
	philo->print_sem = sem_open("/print_sem", O_CREAT, 0644, 1);
	philo->death = sem_open("/death", O_CREAT, 0644, 1);
	philo->start = sem_open("/start", O_CREAT, 0644, 0);
	return (1);
}