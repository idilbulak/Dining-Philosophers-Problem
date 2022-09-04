#include "../inc/philo_bonus.h"

void	death_monitor(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	if (time - ph->time_left > 0)
	{
		sem_wait(ph->sem_isdead);
		printf("%ld %zu died\n", time - ph->start_time, ph->i);
		exit(1);
	}
}
