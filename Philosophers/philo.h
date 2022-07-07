/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:15:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 15:15:29 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define NUM_PHILO_MIN	0
# define NUM_PHILO_MAX	200
# define NUM_PHILO	5
# define TIME_MIN	0
# define TIME_MAX	2520000 //42 minutes
# define NUM_MEAL_MIN	0
# define NUM_MEAL_MAX	200

//Parsing----------------------------------------------------------------------
void	parsing(char **arg);
int		parsing_digit(char **tab);
void	check_0_before_nb(char *str);
int		parsing_limits(char **arg);

//Error messages---------------------------------------------------------------
void	print_parsing_error(int nb);

//Utils------------------------------------------------------------------------
int		ft_isdigit(int c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
