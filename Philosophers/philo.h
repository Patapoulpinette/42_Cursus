/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:15:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 18:27:57 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define PHILO_MIN	1
# define PHILO_MAX	200
# define NUM_PHILO	5
# define TIME_MIN	0
# define TIME_MAX	2520000 //42 minutes
# define MEAL_MIN	0
# define MEAL_MAX	200

//Parsing----------------------------------------------------------------------
int		parsing(int argc, char **argv);
int		check_digits(char *str);
int		check_limits(int arg_nb, char *str);
void	check_0_before_nb(char *str);

//Error messages---------------------------------------------------------------
int		print_parsing_error(int nb);

//Utils------------------------------------------------------------------------
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif