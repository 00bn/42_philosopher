/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:39:21 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/27 11:47:48 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_fork(t_main *main, t_philo *p)
{
	int	i;

	i = 0;
	while (i < main->philo_num)
	{
		if (i == 0 && main->philo_num > 1)
		{
			p[i].right = 0;
			p[i].left = p[i].id;
		}
		else if (i == 0 && main->philo_num == 1)
			p[i].right = 0;
		else if (i != 0 && i != main->philo_num - 1)
		{
			p[i].right = p[i].id - 1;
			p[i].left = p[i].id;
		}
		else if (i == main->philo_num - 1)
		{
			p[i].right = p[i].id - 1;
			p[i].left = 0;
		}
		i++;
	}	
}
