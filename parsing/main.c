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

int	main(void)
{
	char		**txt;
	const char	*PATH = "../map/maptest1.ber";
	int			fd = open(PATH, O_RDONLY);
	int			result;

	result = parsing(fd);

	if (result)
		printf("good Job, your map does work !");
	else
		printf("sorry but your map does not respect the rules.");
}
