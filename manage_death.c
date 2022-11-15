/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:40:58 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/25 14:05:51 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mng_death(t_philo *f)
{
	pthread_mutex_lock(&f->pin->die_flag);
	if (f->pin->im_dead == 0)
	{
		pthread_mutex_unlock(&f->pin->die_flag);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&f->pin->die_flag);
		return (1);
	}
}
