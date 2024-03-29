/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:08:30 by dbouron           #+#    #+#             */
/*   Updated: 2022/03/04 18:16:51 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# if BUFFER_SIZE <= 0
#  error "NEGATIVE BUFFER SIZE"
# endif

# include <stdlib.h>/* pour malloc */
# include <unistd.h>/* pour read() */

char	*get_next_line(int fd);
int		ft_strchr_gnl(const char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len, int mode);
size_t	ft_strlen(const char *s);

#endif