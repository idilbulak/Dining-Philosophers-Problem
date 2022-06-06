#include "../inc/philo.h"

int	get_args_helper(char *argv, long long *nbr)
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
	if(get_args_helper(argv[1], &nbr))
		args->_philos = nbr;
	nbr = 0;
	if(get_args_helper(argv[2], &nbr))
		args->_time_to_die = nbr;
	nbr = 0;
	if(get_args_helper(argv[3], &nbr))
		args->_time_to_eat = nbr;
	nbr = 0;
	if(get_args_helper(argv[4], &nbr))
		args->_time_to_sleep = nbr;
	args->_meals = 0;
	args->option = 0;
}

void	optional_args(char **argv, t_philo *args, long long nbr)
{
	if(get_args_helper(argv[1], &nbr))
		args->_philos = nbr;
	nbr = 0;
	if(get_args_helper(argv[2], &nbr))
		args->_time_to_die = nbr;
	nbr = 0;
	if(get_args_helper(argv[3], &nbr))
		args->_time_to_eat = nbr;
	nbr = 0;
	if(get_args_helper(argv[4], &nbr))
		args->_time_to_sleep = nbr;
	nbr = 0;
	if(get_args_helper(argv[5], &nbr))
		args->_meals = nbr;
	args->option = 1;
}

int	get_args(int argc, char **argv, t_philo *args)
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