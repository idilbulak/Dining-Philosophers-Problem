#include "../inc/philo_bonus.h"

void	ft_print(t_philo *philo, char *str)
{
	long	time;

	time = gettimeofday_ms(time);
	sem_wait(philo->print_sem);
    // sem_waitdeath
	printf("%ld %d %s\n", time - philo->start_time, philo->i, str);
	// sem_postdeath
    sem_post(philo->print_sem);
}

void	death_monitor(t_philo *philo)
{
	long	time;

	time = gettimeofday_ms(time);
	if (time - philo->time_left > 0)
	{
		sem_wait(philo->death);
		printf("%ld %d died\n", time - philo->start_time, philo->i);
        exit (0);
	}
}

static void	ft_eat(t_philo *philo)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(philo, "is eating");
	while (1)
	{
		usleep(100);
		death_monitor(philo);
		if (check_time(time) >= philo->time_to_eat)
			break ;
	}
	time = gettimeofday_ms(time);
	philo->time_left = time + philo->time_to_die;
	philo->meals--;
}

static void	ft_sleep_think(t_philo *philo)
{
	long	time;

	time = gettimeofday_ms(time);
	ft_print(philo, "is sleeping");
	while (1)
	{
		usleep (1000);
		if (check_time(time) >= philo->time_to_sleep)
			break ;
	}
	ft_print(philo, "is thinking");
}

void	ft_tasks(t_philo *philo)
{
	if (philo->i % 2 == 1)
		usleep(1000);
    while (1)
    {
        sem_wait(philo->sem);
        ft_print(philo, "has taken a fork");
        usleep(100);
        sem_wait(philo->sem);
        ft_print(philo, "has taken a fork");
        ft_eat(philo);
        sem_post(philo->sem);
        sem_post(philo->sem);
        ft_sleep_think(philo);
        if (!philo->meals)
            break ;
    }
    exit (0);
}