/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:10:41 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/22 12:18:51 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../lib/printf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_checks
{
	char	key;
	int		value;
}			t_checks;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

t_checks	*ft_find(t_checks *dict, char c);

t_checks	*ft_create(void);

char		**get_text(int fd, char **txt);

int			parsing(char **txt);

void		free_all(char **txt);

int			ft_printf(const char *s, ...);

int			check_truth(t_checks *check);

int			flood(char **txt, int x, int y, char ch);

int			certificate_map(char **txt);

void		find_p(char **txt, int *x, int *y);

#endif
