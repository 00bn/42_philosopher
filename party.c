/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:15:56 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/27 11:26:26 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
	 d = d - f->pin->time_init; + f->info->time_die
	!!im_dead reinit -1 if 
*/
int	death_philo(t_philo *f)
{
	struct timeval	starttime;
	struct timeval	nowtime;
	int				d;

	d = 0;
	gettimeofday(&starttime, NULL);
	f->dead = (starttime.tv_sec * 1000 + starttime.tv_usec / 1000);
	f->dead = f->last_meal + f->dead;
	gettimeofday(&nowtime, NULL);
	d = (nowtime.tv_sec * 1000 + nowtime.tv_usec / 1000);
	d = d - f->pin->time_init;
	if (d - f->last_meal >= f->pin->time_die && \
	(f->last_meal != 0 || f->id < 2) && (mng_death(f) == 0))
	{
		pthread_mutex_lock(&f->pin->die_flag);
		f->pin->im_dead = -1;
		pthread_mutex_unlock(&f->pin->die_flag);
		pthread_mutex_lock(&f->pin->write);
		printf(BWHT"%d %d died\n", printtime(f), f->id);
		pthread_mutex_unlock(&f->pin->write);
		return (0);
	}
	else
		return (1);
}

void	sleep_philo(t_philo *f)
{
	struct timeval	starttime;
	struct timeval	nowtime;
	int				s;

	s = 0;
	gettimeofday(&starttime, NULL);
	f->sleep = ((starttime.tv_sec * 1000) + (starttime.tv_usec / 1000));
	f->sleep += f->pin->time_sleep;
	if (mng_death(f) == 0 && death_philo(f) == 1)
		print_status(f, "is sleeping", BRED);
	while (1 && mng_death(f) == 0)
	{
		gettimeofday(&nowtime, NULL);
		s = (nowtime.tv_sec * 1000 + nowtime.tv_usec / 1000);
		if (s - f->sleep >= 0)
			break ;
		usleep(200);
	}
	f->eat_done = 2;
}

void	eat_philo(t_philo *f)
{
	struct timeval	starttime;
	struct timeval	looptime;
	int				loop_t;

	loop_t = 0;
	gettimeofday(&starttime, NULL);
	f->eat = (starttime.tv_sec * 1000 + starttime.tv_usec / 1000);
	f->eat += f->pin->time_eat;
	if (mng_death(f) == 0)
		print_status(f, "is eating", BGRN);
	get_last_meal_time(f);
	while (1)
	{
		gettimeofday(&looptime, NULL);
		loop_t = (looptime.tv_sec * 1000 + looptime.tv_usec / 1000);
		if (loop_t - f->eat >= 0)
		{
			break ;
		}
		usleep(200);
	}
	if (f->num_time_eat != 0)
			f->count++;
		f->eat_done = 1;
}

int	num_time_eat(t_philo *f)
{
	if (f->num_time_eat > 0)
		return (0);
	else if (f->num_time_eat == -1)
	{
		f->num_time_eat = -1;
		return (0);
	}
	else
		return (1);
}
