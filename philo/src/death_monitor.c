#include "../inc/philo.h"

void	death_monitor(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	if (time - ph->time_left > 0)
	{
		pthread_mutex_lock(&ph->print_mutex[0]);
		if (ph->is_dead[0])
			printf("%ld %d died\n", time - ph->start_time, ph->i);
		ph->is_dead[0] = 0;
		pthread_mutex_unlock(&ph->print_mutex[0]);
	}
}