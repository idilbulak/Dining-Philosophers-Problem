/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 13:00:42 by ibulak        #+#    #+#                 */
/*   Updated: 2022/06/27 13:06:20 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	error_input(void)
{
	printf("ERROR");
	return (0);
}

int	if_correctinput(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				return (-1);
			if (!ft_isdigit(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

void	destroy_mutex(t_philo *philo)
{
	unsigned int	i;

	pthread_mutex_destroy(&(philo->print));
	i = 0;
	while (i < philo->_philos)
	{
		pthread_mutex_destroy(&(philo[i].forks));
		pthread_mutex_destroy(&(philo[i].event));
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*args;

	if (if_correctinput(argv) == -1)
	{
		error_input();
		return (0);
	}
	if (get_args(argc, argv, args) == -1)
	{
		error_input();
		return (0);
	}
	if (initialize(args) == -1)
		return (0);
	if (simulation(args) == -1)
	{
		free(args);
		error_input();
		return (0);
	}
	destroy_mutex(&args);
	free(args);
	return (1);
}
