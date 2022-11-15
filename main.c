/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 09:43:01 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/29 12:05:49 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>

void	phil_loop(t_philo *f)
{
	if (check_fork(f) == 0)
	{
		if (check_gogo(f) == 0)
		{
			if (take_fork(f) == 0 && mng_death(f) == 0)
				eat_philo(f);
			write_gogo(f);
			if (f->eat_done == 1)
				put_fork(f);
		}
	}
	if (f->eat_done == 1 && mng_death(f) == 0 && \
	death_philo(f) == 1)
		sleep_philo(f);
	if (f->eat_done == 2 && mng_death(f) == 0 && \
	death_philo(f) == 1)
	{
		print_status(f, "is thinking", BYEL);
		f->eat_done = 0;
	}
}

void	*begin(void *file)
{
	t_philo	*f;

	f = (t_philo *)file;
	while (1 && mng_death(f) == 0 && death_philo(f) == 1 \
	&& f->count <= f->num_time_eat && mng_death(f) == 0)
	{
		phil_loop(f);
	}
	return (&f->pin->im_dead);
}

void	creat_p(t_main *main, t_philo *p)
{
	int	i;

	i = 0;
	while (i < main->philo_num)
	{
		pthread_create(&main->thread[i], NULL, &begin, &p[i]);
		i++;
		i++;
	}
	usleep(1000);
	i = 1;
	while (i < main->philo_num)
	{
		pthread_create(&main->thread[i], NULL, &begin, &p[i]);
		i++;
		i++;
	}
}

int	start(t_main *main, t_philo *p)
{
	struct timeval	start;
	int				i;

	gettimeofday(&start, NULL);
	main->time_init = (start.tv_sec * 1000 + start.tv_usec / 1000);
	main->thread = (pthread_t *)malloc(sizeof(pthread_t) * main->philo_num);
	assign_fork(main, p);
	creat_p(main, p);
	i = 0;
	while (i < main->philo_num)
	{
		pthread_join(main->thread[i], NULL);
		i++;
	}
	dest(main);
	ft_free(main, p);
	return (1);
}

int	main(int ac, char *av[])
{
	t_main	main;

	if (ac == 5 || ac == 6)
	{
		if (ac == 5 || ac == 6)
		{
			check_input(ac, av);
			init(&main, ac, av);
			init_arr(&main);
			init_locks(&main);
			return (init_struct(&main));
		}
	}
	else
		printf("WRONK NUMBER OF ARGUMENTS\n");
}
