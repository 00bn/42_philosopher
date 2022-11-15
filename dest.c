/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dest.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:41:41 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/27 11:16:36 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dest(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->philo_num)
	{
		pthread_mutex_destroy(&main->main_lock[i]);
		i++;
	}
	i = 0;
	while (i < main->philo_num)
	{
		pthread_mutex_destroy(&main->gogo_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	pthread_mutex_destroy(&main->die_flag);
}
