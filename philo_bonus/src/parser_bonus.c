/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:40:39 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/06 15:00:33 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	invalid_input(int i, char **argv)
{
	int	j;

	if (i != 5 && i != 6)
		return (1);
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				return (1);
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) > MAX_INT)
			return (1);
		i++;
	}
	return (0);
}

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

t_philo	parser(int argc, char **argv, t_philo ph)
{
	ph.n_philos = (int)ft_atoi(argv[1]);
	ph.time_to_die = (int)ft_atoi(argv[2]);
	ph.time_to_eat = (int)ft_atoi(argv[3]);
	ph.time_to_sleep = (int)ft_atoi(argv[4]);
	if (argc == 6)
		ph.meals = (int)ft_atoi(argv[5]);
	else
		ph.meals = -1;
	return (ph);
}
