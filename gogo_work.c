/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gogo_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:55:36 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/26 09:35:54 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	check_gogo(t_philo *f)
{
	int	r;
	int	l;

	r = 0;
	l = 0;
	pthread_mutex_lock(&f->pin->gogo_lock[f->right]);
	if (f->pin->gogo_fork[f->right] != f->id)
	{
		pthread_mutex_unlock(&f->pin->gogo_lock[f->right]);
		r = -1;
	}
	else
		pthread_mutex_unlock(&f->pin->gogo_lock[f->right]);
	pthread_mutex_lock(&f->pin->gogo_lock[f->left]);
	if (f->pin->gogo_fork[f->left] != f->id)
	{
		pthread_mutex_unlock(&f->pin->gogo_lock[f->left]);
		l = -1;
	}
	else
		pthread_mutex_unlock(&f->pin->gogo_lock[f->left]);
	if (r == -1 && l == -1)
		return (0);
	else
		return (1);
}

void	write_gogo(t_philo *f)
{
	pthread_mutex_lock(&f->pin->gogo_lock[f->right]);
	if (f->pin->gogo_fork[f->right] != f->id)
	{
		f->pin->gogo_fork[f->right] = f->id;
		pthread_mutex_unlock(&f->pin->gogo_lock[f->right]);
	}
	else
		pthread_mutex_unlock(&f->pin->gogo_lock[f->right]);
	pthread_mutex_lock(&f->pin->gogo_lock[f->left]);
	if (f->pin->gogo_fork[f->left] != f->id)
	{
		f->pin->gogo_fork[f->left] = f->id;
		pthread_mutex_unlock(&f->pin->gogo_lock[f->left]);
	}
	else
		pthread_mutex_unlock(&f->pin->gogo_lock[f->left]);
}
