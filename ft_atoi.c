/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 11:27:11 by balnahdi          #+#    #+#             */
/*   Updated: 2022/08/20 11:27:12 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

void	atoi_split(t_atoi *h, const char *str)
{
	h->k = h->k * 10 + str[h->i] - '0';
	if (h->k >= 2147483648 && h->j > 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (h->k >= 2147483649 && h->j < 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	h->i++;
}

int	ft_atoi(const char *str)
{
	t_atoi	h;

	h.k = 0;
	h.i = 0;
	h.j = 1;
	while (str[h.i] == ' ' || str[h.i] == '\n' || str[h.i] == '\t'
		|| str[h.i] == '\r' || str[h.i] == '\v' || str[h.i] == '\f')
		h.i++;
	if (str[h.i] == '-')
		h.j *= -1;
	if (str[h.i] == '+' || str[h.i] == '-')
		h.i++;
	while (str[h.i] >= '0' && str[h.i] <= '9')
		atoi_split(&h, str);
	return ((int )h.k * h.j);
}
