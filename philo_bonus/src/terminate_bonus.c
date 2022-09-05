/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   terminate_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/05 12:46:14 by ibulak        #+#    #+#                 */
/*   Updated: 2022/09/05 12:46:15 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_terminate(t_philo *ph)
{
	sem_unlink("/sem_forks");
	sem_close(ph->sem_forks);
	sem_unlink("/sem_print");
	sem_close(ph->sem_print);
	sem_unlink("/is_dead");
	sem_close(ph->sem_isdead);
	sem_unlink("/start");
	sem_close(ph->sem_last);
	free(ph->pid);
}
