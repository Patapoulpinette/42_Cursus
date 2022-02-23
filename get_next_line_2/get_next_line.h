/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbouron <dbouron@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:03:58 by dbouron           #+#    #+#             */
/*   Updated: 2022/02/23 16:26:36 by dbouron          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>/* pour malloc */
# include <unistd.h>/* pour read() */
# include <fcntl.h>/* pour tester */
# include <stdio.h>/* pour tester */

char	*get_next_line(int fd);
int		ft_strchr_gnl(const char *s, char c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);

#endif