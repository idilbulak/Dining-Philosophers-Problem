#include "../inc/philo.h"

long	gettimeofday_ms(long time)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	time= (current.tv_sec * 1000) + (current.tv_usec / 1000);
	return (time);
}

long  time_check(long time)
{
	long            now;

	now = gettimeofday_ms(now);
	return (now - time);
}