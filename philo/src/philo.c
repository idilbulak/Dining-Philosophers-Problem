#include "../inc/philo.h"

int	invalid_input(int i, char **argv)
{
	int j;

	if (i != 5 && i != 6)
		return (1);
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] == '-')
				return (1);
			if(!ft_isdigit(argv[i][j]))
				return(1);
			j++;
		}
		if (ft_atoi(argv[i]) > MAX_INT)
			return (1);
		i++;
	}
	return(0);
}

int main(int argc, char **argv)
{
	t_philo p;

	if (invalid_input(argc, argv))
		return (1);
	p = parser(argc, argv, p);
	if (p.n_philos == 0)
		return (1);
	else if (p.n_philos == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(p.time_to_die * 1000);
		printf("%d 1 died\n", p.time_to_die);
	}
	else
	{
		if (ft_initialize(&p))
			return (1);
		p.i = 1;
		while (p.i <= p.n_philos)
		{
			pthread_create(&p.thread[p.i], NULL, routine, &p);
			usleep(100);
			p.i++;
		}
		p.i = 1;
		while (p.i <= p.n_philos)
		{
			pthread_join(p.thread[p.i], NULL);
			p.i++;
		}
		ft_terminate(&p);
	}
	return (0);
}
