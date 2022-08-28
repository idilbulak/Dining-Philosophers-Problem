#include "../inc/philo.h"

void	ft_terminate(t_philo *p)
{
	int	i;

	i = 0;
	while (i <= p->n_philos)
	{
		pthread_mutex_destroy(&p->mutex[i]);
		i++;
	}
	pthread_mutex_destroy(&p->print_mutex[0]);
	free(p->mutex);
	free(p->print_mutex);
	free(p->thread);
}