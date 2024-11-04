/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:40:21 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/04 14:16:05 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

char	*ft_checkline(char *buffer, int fd);

int		ft_strlen(char *c);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strchr(char c, char *s);

char	*ft_strdup(char *s);

char	*get_next_line(int fd, int check);

void	*ft_calloc(size_t nmemb, size_t size);

#endif
