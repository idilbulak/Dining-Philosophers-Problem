#include "../inc/philo_bonus.h"

int	ft_isdigit(char c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	else
		return (1);
}

int	ft_strlen(const char *s)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] == s2[x] && s1[x] != '\0' && s2[x] != '\0' && x < n - 1)
	{
		if (s1[x] != s2[x])
			break ;
		x++;
	}
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}