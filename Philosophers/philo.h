/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:15:59 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 12:00:13 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define NUM_PHILO_MAX	200
# define NUM_PHILO	5

//Parsing----------------------------------------------------------------------
int		ft_isdigit(int c);
void	parsing(char **arg);

//Utils------------------------------------------------------------------------
int		ft_atoi(const char *str);
int		parsing_digit(char **tab);
void	check_0_before_nb(char *str);
int		errors(char **arg);

#endif
