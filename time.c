/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:53:32 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/26 10:17:10 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	printtime(t_philo *f)
{
	struct timeval	nowtime;
	int				time;

	gettimeofday(&nowtime, NULL);
	time = (nowtime.tv_sec * 1000 + nowtime.tv_usec / 1000);
	return (time - f->pin->time_init);
}

void	get_last_meal_time(t_philo *f)
{
	struct timeval	nowtime;
	int				time;

	gettimeofday(&nowtime, NULL);
	time = (nowtime.tv_sec * 1000 + nowtime.tv_usec / 1000);
	f->last_meal = time - f->pin->time_init;
}
