/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/12 15:29:19 by ibulak        #+#    #+#                 */
/*   Updated: 2022/04/12 16:28:42 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	error_input(void)
{
	red();
	printf("Wrong inputs!");
	reset();
	return (0);
}

int	check_inputs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc != 5)
	{
		error_input();
		return (0);
	}
	while (i < 5)
	{
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else
			{
				error_input();
				return (0);
			}
		}
		i++;
	}
	if (!ft_strncmp("0", argv[1], 4))
	{
		yellow();
		printf("There should be some philos if you want to starve them!");
		reset();
		return (0);
	}
	if (!ft_strncmp("1", argv[1], 4))
	{
		yellow();
		printf("A philosopher can not eat the noodle with only one chopstick!");
		reset();
		return (0);
	}
	if (!ft_strncmp("0", argv[2], 4))
	{
		yellow();
		printf("BOM! You killed all of the philos!");
		reset();
		return (0);
	}
	if (!ft_strncmp("0", argv[3], 4))
	{
		yellow();
		printf("Can a philo eat in 0 sec?");
		reset();
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;

	if (check_inputs(argc, argv))
	{
		number_of_philosophers = ft_atoi(argv[1]);
		time_to_die = ft_atoi(argv[2]);
		time_to_eat = ft_atoi(argv[3]);
		time_to_sleep = ft_atoi(argv[4]);
		blue();
		printf("number_of_philosophers:");
		reset();
		printf("%d\n", number_of_philosophers);
		blue();
		printf("time_to_die:");
		reset();
		printf("%d\n", time_to_die);
		blue();
		printf("time_to_eat:");
		reset();
		printf("%d\n", time_to_eat);
		blue();
		printf("time_to_sleep:");
		reset();
		printf("%d\n", time_to_sleep);
		reset();
	}
	return (0);
}
