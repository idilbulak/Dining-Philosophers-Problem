#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

void		*routine(void *val);

int			ft_isdigit(char c);
int			ft_strlen(const char *s);
static int	ft_isspace(char c);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			check_inputs(int argc, char **argv);
int			error_input(void);

void red();

void yellow();
void blue();


void reset();

# endif