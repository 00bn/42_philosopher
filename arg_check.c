/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:40:44 by balnahdi          #+#    #+#             */
/*   Updated: 2022/08/20 11:41:14 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && ((str[i + 1] == ' ' || str[i + 1] == '\0') \
		|| (str[i + 1] >= '0' || str[i + 1] < '9')))
			return (0);
		else if (str[i] == '+' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			return (0);
		i++;
	}	
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	check_input(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_arg(argv[i]) == 1)
			i++;
		else
		{
			printf("Invalid arguments\n");
			exit(0);
		}
	}
}
