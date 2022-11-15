/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:14:52 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/29 12:00:57 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	print_status(t_philo *f, char *msg, char *color)
{
	pthread_mutex_lock(&f->pin->die_flag);
	if (f->pin->im_dead == 0)
	{
		printf("%s%d %d %s\n", color, printtime(f), f->id, msg);
		pthread_mutex_unlock(&f->pin->die_flag);
	}
	else
		pthread_mutex_unlock(&f->pin->die_flag);
}
