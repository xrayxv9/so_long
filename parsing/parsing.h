/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:10:41 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/06 10:23:41 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_checks
{
	char key;
	int	value;
}			t_checks;

t_checks	*ft_find(t_checks *dict, char c);

t_checks	*ft_create(void);

char		**get_text(int fd, char **txt);

int			parsing(char **txt);

void	free_all(char **txt);

int		ft_printf(const char *s, ...);

#endif
