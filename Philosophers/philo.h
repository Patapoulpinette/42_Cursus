/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:15:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/19 11:08:00 by dbouron          ###   ########.fr       */
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
	int			philo_nbr;
	time_t		t_die;
	time_t		t_eat;
	time_t		t_sleep;
	int			eat_num;
}				t_param;

typedef struct s_thread_info
{
	pthread_t	thread_id;
	int			philo_num;
	short		philo_status;
	time_t		t_last_meal;
	int			fork;
	t_param		param;
}				t_thread_info;

//Parsing----------------------------------------------------------------------
int		parsing(int argc, char **argv, t_param *param);
int		check_digits(char *str);
int		check_limits(int arg_nb, char *str);
void	check_0_before_nb(char *str);
void	save_params(char **argv, t_param *param);

//Execution---------------------------------------------------------------------
int		execution(t_param *param, t_thread_info *philos);
void	*philos_routine(void *philo_thread);

//Ending------------------------------------------------------------------------
int		ending(t_param *param, t_thread_info *philos_group);

//Error messages---------------------------------------------------------------
int		print_parsing_error(int nb);

//Utils------------------------------------------------------------------------
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t type_size);

#endif