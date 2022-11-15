/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balnahdi <balnahdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:52:30 by balnahdi          #+#    #+#             */
/*   Updated: 2022/09/28 20:09:13 by balnahdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
// #include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

# define BBLK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGRN "\e[1;32m"
# define BYEL "\e[1;33m"
# define BBLU "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYN "\e[1;36m"
# define BWHT "\e[1;37m"
# define RESET "\e[0m"
# define CRESET "\e[0m"
# define COLOR_RESET "\e[0m"

typedef struct s_atoi
{
	unsigned long int	k;
	int					i;
	int					j;
}t_atoi;

typedef struct s_main
{
	int				*fork;
	int				*gogo_fork;
	pthread_t		*thread;
	pthread_mutex_t	*main_lock;
	pthread_mutex_t	*gogo_lock;
	pthread_mutex_t	write;
	pthread_mutex_t	die_flag;
	int				im_dead;
	int				party_flag;
	int				philo_num;
	int				num_time_eat;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				time_init;

}t_main;

typedef struct s_philo
{
	int		r;
	int		l;
	int		right;
	int		left;
	int		check_r;
	int		check_l;
	int		id;
	int		sleep;
	int		dead;
	int		eat;
	int		eat_done;
	int		sleep_done;
	int		num_time_eat;
	int		count;
	int		last_meal;
	t_main	*pin;
}t_philo;

//ft_atoi
int		ft_atoi(const char *str);

//check arg
int		check_arg(char *str);
void	check_input(int argc, char *argv[]);

void	init(t_main *main, int ac, char *av[]);
void	init_arr(t_main *main);
void	init_locks(t_main *main);
int		init_struct(t_main *main);
void	fill_philo(t_philo *p, int i, t_main *m);
void	assign_fork(t_main *main, t_philo *p);

int		start(t_main *main, t_philo *p);
void	*begin(void *file);

//time 
int		printtime(t_philo *f);
void	get_last_meal_time(t_philo *f);

//party
int		death_philo(t_philo *f);
void	sleep_philo(t_philo *f);
void	eat_philo(t_philo *f);
int		num_time_eat(t_philo *f);

//fork_work
int		check_fork(t_philo *f);
int		take_fork(t_philo *f);
void	put_fork(t_philo *f);

//gogo_work
int		check_gogo(t_philo *f);
void	write_gogo(t_philo *f);

//dest
void	dest(t_main *main);

//manage death
int		mng_death(t_philo *f);

//print_staus
void	print_status(t_philo *f, char *msg, char *color);

//free

void	ft_free(t_main *main, t_philo *p);

#endif
