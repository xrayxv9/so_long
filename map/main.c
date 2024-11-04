// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.c                                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: xray <xray@42angouleme.fr>                 +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/11/03 17:32:05 by xray              #+#    #+#             //
//   Updated: 2024/11/03 19:29:12 by xray             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //
#include "parsing.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char **txt;
	const char *PATH = "maptest1.ber";
	int fd = open(PATH, O_RDONLY);
	int i = 0;

	txt = malloc (1 * sizeof(char *));
	txt[0] = NULL;
	txt = parsing(fd, txt);
	while (txt[i])
	{
		printf("%s", txt[i]);
		free(txt[i]);
		i++;
	}
	free(txt);
}
