/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 13:30:48 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/28 20:09:04 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_free_locks(t_main *main)
{
	free(main->main_lock);
	free(main->gogo_lock);
}

void	ft_free(t_main *main, t_philo *p)
{
	free(main->fork);
	free(main->gogo_fork);
	free(main->thread);
	free(p);
	ft_free_locks(main);
}
