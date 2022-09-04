#include "../inc/philo.h"

void	ft_eat(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(ph, CYAN, "is eating");
	while(1)
	{
		usleep(100);
		death_monitor(ph);
		if (time_check(time) > ph->time_to_eat)
			break ;
	}
	time = gettimeofday_ms(time);
	ph->time_left = time + ph->time_to_die;
	ph->meals--;
}

void	ft_sleep_think(t_philo *ph)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(ph, PURPLE, "is sleeping");
	while (1)
	{
		usleep(100);
		if (time_check(time) > ph->time_to_sleep)
			break ;
	}
	ft_print(ph, GREEN, "is thinking");
}

void    *routine(void   *p)
{
	t_philo ph;

	ph = *(t_philo *)p;
    ph.lfork = ph.i;
	ph.rfork = ph.i + 1;
	if (ph.i == ph.n_philos)
		ph.rfork = 1;
	while (1)
	{
		if(time_check(ph.start_time) >= 1000)
			break ;
		usleep(300); //bak
	}
	ph.start_time = gettimeofday_ms(ph.start_time);
	ph.time_left = ph.start_time + ph.time_to_die;
	if (ph.i % 2 == 1)
		usleep(1000);
	while (ph.is_dead[0])
	{
		pthread_mutex_lock(&ph.mutex[ph.rfork]);
		ft_print(&ph, YELLOW, "has taken a fork");
		usleep (50);
		pthread_mutex_lock(&ph.mutex[ph.lfork]);
		ft_print(&ph, YELLOW, "has taken a fork");
		ft_eat(&ph);
		pthread_mutex_unlock(&ph.mutex[ph.lfork]);
		pthread_mutex_unlock(&ph.mutex[ph.rfork]);
		ft_sleep_think(&ph);
		if (!ph.meals)
			break ;
	}
	return (NULL);
}