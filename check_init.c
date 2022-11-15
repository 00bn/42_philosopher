/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:35:47 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/28 19:44:59 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	init_arg(int i, int num, int ac, t_main *main)
{
	if (i == 1 && num > 0)
		main->philo_num = num;
	else if (i == 2 && num > 0)
		main->time_die = num;
	else if (i == 3 && num > 0)
		main->time_eat = num;
	else if (i == 4 && num > 0)
		main->time_sleep = num;
	else if (i == 5 && num > 0)
	{
		if (ac == 5)
			main->num_time_eat = 0;
		if (ac == 6)
			main->num_time_eat = num;
	}
	else if (num <= 0)
	{
		printf("One or more arguments are wrong\n");
		exit(0);
	}
}

//Fill aguments in main
void	init(t_main *main, int ac, char *av[])
{
	int	i;
	int	num;

	num = 0;
	i = 1;
	while (i < ac)
	{
		num = ft_atoi(av[i]);
		init_arg(i, num, ac, main);
		i++;
	}
	if (ac == 5)
		main->num_time_eat = 0;
	main->time_init = 0;
	main->im_dead = 0;
}
