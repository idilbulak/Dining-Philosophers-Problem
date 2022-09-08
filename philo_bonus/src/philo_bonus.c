/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:40:49 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/06 15:07:29 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	ph;

	if (invalid_input(argc, argv))
		return (1);
	ph = parser(argc, argv, ph);
	if (ph.n_philos == 0)
		return (1);
	else if (ph.n_philos == 1)
	{
		printf("0\t%s[P1] has taken a fork%s\n", YELLOW, RESET);
		usleep(ph.time_to_die * 1000);
		printf("%s%d\t[P1] died\n", RED, ph.time_to_die);
		return (1);
	}
	else
	{
		ft_initialize(&ph);
		simulation(ph);
		ft_terminate(&ph);
	}
	return (0);
}
