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
	t_philo ph;

	if (invalid_input(argc, argv))
		return (1);
	ph = parser(argc, argv, ph);
	if (ph.n_philos == 0)
		return (1);
	else if (ph.n_philos == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(ph.time_to_die * 1000);
		printf("%d 1 died\n", ph.time_to_die);
		return(1);
	}
	else
	{
		if (ft_initialize(&ph))
			return (1);
		ph.i = 1;
		while (ph.i <= ph.n_philos)
		{
			pthread_create(&ph.thread[ph.i], NULL, routine, &ph);
			usleep(100);
			ph.i++;
		}
		ph.i = 1;
		while (ph.i <= ph.n_philos)
		{
			pthread_join(ph.thread[ph.i], NULL);
			ph.i++;
		}
		ft_terminate(&ph);
		return (0);
	}
}
