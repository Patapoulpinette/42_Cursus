/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 10:13:21 by dbouron           #+#    #+#             */
/*   Updated: 2022/07/07 18:23:30 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*print_hello(void *threadid)
{
	long	tid;

	tid = (long)threadid;
	printf("Hello! It's me, thread #%ld!\n", tid);
	pthread_exit(NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	threads[PHILO_MAX];
	int			rc;
	long		t;

	if (parsing(argc, argv))
		return (EXIT_FAILURE);
	t = 0;
	while (t < NUM_PHILO)
	{
		printf("In main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, print_hello, (void *) t);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			return (EXIT_FAILURE);
		}
		t++;
	}
	return (0);
}
