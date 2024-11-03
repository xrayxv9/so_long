// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   parsing.h                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/10/31 21:21:34 by xray              #+#    #+#             //
//   Updated: 2024/11/03 17:42:00 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_checks
{
	char	key;
	int		value;
}		t_checks;

t_checks	*find(t_checks *dict, char c);

t_checks	*create(void);

char		**parsing(int fd, char **txt);

#endif
