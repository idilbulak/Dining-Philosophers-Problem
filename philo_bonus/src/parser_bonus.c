#include "../inc/philo_bonus.h"

int	if_correctinput(char **argv)
{
	int i;
	int j;

	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if(argv[i][j] == '-')
				return (-1);
			if(!ft_isdigit(argv[i][j]))
				return(-1);
			j++;
		}
		i++;
	}
	return(1);
}

int	args_helper(char *argv, long long *nbr)
{
	int	i;

	i = 0;
	while (ft_isdigit(argv[i]))
	{
		*nbr = *nbr * 10 + (argv[i] - '0');
		i++;
	}
	if (*nbr > MAX_INT)
		return(-1);
	return(1);
}

void	required_args(char **argv, t_philo *args, long long nbr)
{
	if(args_helper(argv[1], &nbr))
		args->n_philos = nbr;
	nbr = 0;
	if(args_helper(argv[2], &nbr))
		args->time_to_die = nbr;
	nbr = 0;
	if(args_helper(argv[3], &nbr))
		args->time_to_eat = nbr;
	nbr = 0;
	if(args_helper(argv[4], &nbr))
		args->time_to_sleep = nbr;
	args->meals = 0;
}

void	optional_args(char **argv, t_philo *args, long long nbr)
{
	if(args_helper(argv[1], &nbr))
		args->n_philos = nbr;
	nbr = 0;
	if(args_helper(argv[2], &nbr))
		args->time_to_die = nbr;
	nbr = 0;
	if(args_helper(argv[3], &nbr))
		args->time_to_eat = nbr;
	nbr = 0;
	if(args_helper(argv[4], &nbr))
		args->time_to_sleep = nbr;
	nbr = 0;
	if(args_helper(argv[5], &nbr))
		args->meals = nbr;
}

int	parser(int argc, char **argv, t_philo *args)
{
	long long nbr;

	nbr = 0;
	if(argc == 5)
	{
		required_args(argv, args, nbr);
		return(1);
	}
	if(argc == 6)
	{
		optional_args(argv, args, nbr);
		return(1);
	}
	return(-1);
}