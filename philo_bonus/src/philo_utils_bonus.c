#include "../inc/philo_bonus.h"

void	ft_print(t_philo *ph, char *color, char *str)
{
	long	time;

	time = gettimeofday_ms(time);
	
	sem_wait(ph->sem_print);
	sem_wait(ph->sem_isdead);
	printf("%ld\t%s[P%zu] %s\n%s", time - ph->start_time, color, ph->i, str, RESET);
	sem_post(ph->sem_isdead);
	sem_post(ph->sem_print);
}