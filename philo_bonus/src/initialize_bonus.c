#include "../inc/philo_bonus.h"

void	ft_initialize(t_philo *ph)
{
	ph->pid = malloc((ph->n_philos + 1) * sizeof(int));
	if (!ph->pid)
		exit(1);
	memset(ph->pid, 0, ph->n_philos + 1);
	sem_unlink("/sem_forks");
	ph->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, ph->n_philos);
	sem_unlink("/sem_print");
	ph->sem_print = sem_open("/sem_print", O_CREAT, 0644, 1);
	sem_unlink("/sem_isdead");
	ph->sem_isdead = sem_open("/sem_isdead", O_CREAT, 0644, 1);
	sem_unlink("/sem_last");
	ph->sem_last = sem_open("/sem_last", O_CREAT, 0644, 0);
	if (ph->sem_forks == SEM_FAILED || ph->sem_print == SEM_FAILED \
	|| ph->sem_isdead == SEM_FAILED || ph->sem_last == SEM_FAILED)
		exit(1);
}

