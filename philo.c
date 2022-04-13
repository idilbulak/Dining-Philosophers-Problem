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

#include <pthread.h>
#include <stdio.h>

int	ft_isdigit(char c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

size_t	ft_strlen(const char *s)
{
	int	n;

	n = 0;
	while (!(s[n] == '\0'))
		n++;
	return (n);
}

static int	ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	unsigned long	value;
	int				sign;

	sign = 1;
	value = 0;
	while ((ft_isspace(*str)))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '+' || *str == '-')
		return (0);
	while (ft_isdigit(*str))
	{
		value = value * 10 + (int)(*str - '0');
		str++;
	}
	return (value * sign);
}

int	error_input(void)
{
	printf("Wrong inputs!");
	return (0);
}

int	check_inputs(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5)
	{
		error_input();
		return (0);
	}
	else
	{
		while (i < 5)
		{
			if (!ft_isdigit(*argv[i]))
			{
				error_input();
				break ;
			}
			i++;
		}
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
	}
	printf("nice");
}
