/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:09:11 by dbouron           #+#    #+#             */
/*   Updated: 2021/11/12 17:26:52 by dbouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t type_size)
{
	void	*result;

	result = malloc(count * type_size);
	if (!result)
		return (NULL);
	ft_bzero (result, count * type_size);
	return (result);
}