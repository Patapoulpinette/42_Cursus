/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:15:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/23 17:30:32 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

# define PHILO_MIN	1
# define PHILO_MAX	200
# define TIME_MIN	0
# define TIME_MAX	2520000 //42 minutes
# define MEAL_MIN	0
# define MEAL_MAX	200

# define HAS_FORK	1
# define HAS_FORKS	2
# define HAS_EATEN	3
# define HAS_SLEPT	4
# define THINKING	5
# define HAS_DIED	6

typedef struct s_param
{
	int				philo_nbr;
	time_t			t_die;
	time_t			t_eat;
	time_t			t_sleep;
	int				eat_num;
	time_t			start_time;
	pthread_mutex_t	display;
}				t_param;

typedef struct s_thread_info
{
	pthread_t		thread_id;
	int				philo_num;
	short			philo_status;
	time_t			t_last_meal;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_param			*param;
}				t_thread_info;

//Parsing----------------------------------------------------------------------
int		parsing(int argc, char **argv, t_param *param);
int		check_digits(char *str);
int		check_limits(int arg_nb, char *str);
void	check_0_before_nb(char *str);
void	save_params(char **argv, t_param *param);

//Execution---------------------------------------------------------------------
int		initialization(t_thread_info *philos, int thread_num, t_param *param);
int		execution(t_param *param, t_thread_info *philos);
void	*philos_routine(void *philo_thread);

//Actions-----------------------------------------------------------------------
void	ft_take_fork(t_thread_info *philo);
void	ft_eat(t_thread_info *philo);
void	ft_sleep(t_thread_info *philo);
void	ft_think(t_thread_info *philo);
void	ft_die(t_thread_info *philo);

//Ending------------------------------------------------------------------------
int		ending(t_param *param, t_thread_info *philos_group);

//Messages---------------------------------------------------------------
int		print_parsing_error(int nb);
void	print_action(t_thread_info *philo, int action);

//Utils------------------------------------------------------------------------
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t type_size);

//Time--------------------------------------------------------------------------
time_t	get_time(void);

#endif