/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:55:42 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/28 19:44:09 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

//init each elem in array of struct
void	fill_philo(t_philo *p, int i, t_main *m)
{
	p->id = i + 1;
	p->left = 0;
	p->right = 0;
	p->check_r = 0;
	p->check_l = 0;
	p->eat = 0;
	p->sleep = 0;
	p->dead = 0;
	p->last_meal = 0;
	p->eat_done = 0;
	p->sleep_done = 0;
	p->num_time_eat = m->num_time_eat;
	if (m->num_time_eat == 0)
		p->count = 0;
	else
		p->count = 1;
	p->pin = m;
}

//allocat array of structure AND start()
int	init_struct(t_main *main)
{
	t_philo	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(t_philo) * main->philo_num);
	while (i < main->philo_num)
	{
		fill_philo(&p[i], i, main);
		i++;
	}
	return (start(main, p));
}

//Allocate and init "mutex locks" gogo_lock, main_lock, write lock
void	init_locks(t_main *main)
{
	int	j;

	j = 0;
	main->main_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	main->philo_num);
	while (j < main->philo_num)
	{
		pthread_mutex_init(&main->main_lock[j], NULL);
		j++;
	}
	main->gogo_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	main->philo_num);
	j = 0;
	while (j < main->philo_num)
	{
		pthread_mutex_init(&main->gogo_lock[j], NULL);
		j++;
	}
	pthread_mutex_init(&main->write, NULL);
	pthread_mutex_init(&main->die_flag, NULL);
}

//Allocate and init gogo_forks and forks 
void	init_arr(t_main *main)
{
	int	j;

	j = 0;
	main->fork = malloc(sizeof(int) * main->philo_num);
	while (j < main->philo_num)
	{
		main->fork[j] = 0;
		j++;
	}
	main->gogo_fork = malloc(sizeof(int) * main->philo_num);
	j = 0;
	while (j < main->philo_num)
	{
		main->gogo_fork[j] = 0;
		j++;
	}
}
