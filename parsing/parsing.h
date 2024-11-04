#ifndef PARSING_H
# define PARSING_H

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_checks
{
	char key;
	int	value;
}			t_checks;

t_checks	*find(t_checks *dict, char c);

t_checks	*create(void);

char		**get_text(int fd, char **txt);

int			parsing(int fd);

void	free_all(char **txt);

#endif
