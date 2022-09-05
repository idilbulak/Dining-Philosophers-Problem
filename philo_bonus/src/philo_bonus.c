/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:40:49 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:45:41 by ibulak        ########   odam.nl         */
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

void	ft_kill(t_philo ph)
{
	size_t	i;

	i = 1;
	while (i <= ph.n_philos)
	{
		kill(ph.pid[i], SIGKILL);
		i++;
	}
}

void	simulation(t_philo ph)
{
	int		status;

	ph.i = 1;
	while (ph.i <= ph.n_philos)
	{
		ph.pid[ph.i] = fork();
		if (ph.pid[ph.i] == 0)
			routine(&ph);
		ph.i++;
	}
	ph.i = 1;
	while (ph.i <= ph.n_philos)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			ft_kill(ph);
			break ;
		}
		ph.i++;
	}
}

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
	}
	ft_terminate(&ph);
	return (0);
}
