/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:27:16 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/28 19:57:33 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	check_fork(t_philo *f)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	pthread_mutex_lock(&f->pin->main_lock[f->right]);
	if (f->pin->fork[f->right] == 0)
	{
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
		i = -1;
	}
	else
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
	pthread_mutex_lock(&f->pin->main_lock[f->left]);
	if (f->pin->fork[f->left] == 0)
	{
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
		k = -1;
	}
	else
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
	if (i == -1 && k == -1)
		return (0);
	else
		return (1);
}

void	check_r_l_fork(t_philo *f)
{
	pthread_mutex_lock(&f->pin->main_lock[f->right]);
	if (f->pin->fork[f->right] == 0)
	{
		f->pin->fork[f->right] = 1;
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
		f->r = -1;
	}
	else
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
	pthread_mutex_lock(&f->pin->main_lock[f->left]);
	if (f->pin->fork[f->left] == 0)
	{
		f->pin->fork[f->left] = 1;
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
		f->l = -1;
	}
	else
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
}

void	print_take_fork(t_philo *f)
{
	print_status(f, "has taken a fork", BBLU);
	print_status(f, " has taken a fork", BBLU);
}

int	take_fork(t_philo *f)
{
	f->l = 0;
	f->r = 0;
	check_r_l_fork(f);
	if (f->r == 0 && f->l == -1)
	{
		pthread_mutex_lock(&f->pin->main_lock[f->left]);
		f->pin->fork[f->left] = 0;
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
		return (1);
	}
	else if (f->r == -1 && f->l == 0)
	{
		pthread_mutex_lock(&f->pin->main_lock[f->right]);
		f->pin->fork[f->right] = 0;
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
		return (1);
	}
	else if (f->r == -1 && f->l == -1)
	{
		print_take_fork(f);
		return (0);
	}
	else if (f->r == 0 && f->l == 0)
		return (1);
	return (1);
}

void	put_fork(t_philo *f)
{
	pthread_mutex_lock(&f->pin->main_lock[f->right]);
	if (f->pin->fork[f->right] == 1)
	{
		f->pin->fork[f->right] = 0;
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
	}
	else
		pthread_mutex_unlock(&f->pin->main_lock[f->right]);
	pthread_mutex_lock(&f->pin->main_lock[f->left]);
	if (f->pin->fork[f->left] == 1)
	{
		f->pin->fork[f->left] = 0;
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
	}
	else
		pthread_mutex_unlock(&f->pin->main_lock[f->left]);
}
