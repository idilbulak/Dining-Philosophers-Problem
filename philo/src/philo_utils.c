#include "../inc/philo.h"

void	ft_print(t_philo *ph, char *color, char *str)
{
	long	time;

	time = gettimeofday_ms(time);
	pthread_mutex_lock (&ph->print_mutex[0]);
	if (ph->is_dead[0])
		printf("%ld\t%s[P%d] %s\n%s", time - ph->start_time, color, ph->i, str, RESET);
	pthread_mutex_unlock (&ph->print_mutex[0]);
}

