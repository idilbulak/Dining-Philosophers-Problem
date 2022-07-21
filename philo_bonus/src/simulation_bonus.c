#include "../inc/philo_bonus.h"

long	check_time(long start_time)
{
	long			time;

	time = gettimeofday_ms(time);
	return (time - start_time);
}

void	*routine(t_philo *philo)
{
	if (philo->i != philo->n_philos)
        sem_wait(philo->start);
    sem_post(philo->start);
	philo->start_time = gettimeofday_ms(philo->start_time);
	philo->time_left = philo->start_time + philo->time_to_die;
	ft_tasks(philo);
}

int	simulation(t_philo philo)
{
    int i;
    int *stat_loc;

    i = 1;
	while (philo.i <= philo.n_philos)
	{
        philo.id[philo.i] = fork();
        if (philo.id[philo.i] == 0)
            routine(&philo);
		philo.i++;
	}
	philo.i = 1;
    while (philo.i <= philo.n_philos)
    {
        waitpid(-1, stat_loc, 0);
        if (stat_loc != 0)
        {
            while (i <= philo.n_philos)
            {
                kill(philo.id[i], SIGKILL);
                i++;
            }
            break ;
        }
        philo.i++;
    }
	return (1);
}