#include "../inc/philo_bonus.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(char *argv)
{
	long	nbr;

	nbr = 0;
	while (ft_isdigit(*argv))
	{
		nbr = nbr * 10 + (*argv - '0');
		argv++;
	}
	return (nbr);
}

t_philo	parser(int argc, char **argv, t_philo p)
{
	p.n_philos = (int)ft_atoi(argv[1]);
	p.time_to_die = (int)ft_atoi(argv[2]);
	p.time_to_eat = (int)ft_atoi(argv[3]);
	p.time_to_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		p.meals = (int)ft_atoi(argv[5]);
	else
		p.meals = -1;
	return (p);
}