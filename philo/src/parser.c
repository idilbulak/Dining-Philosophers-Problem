/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 11:39:28 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 11:39:29 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
