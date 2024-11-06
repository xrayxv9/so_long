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

int	main(int argc, char **argv)
{
	const char	*PATH = argv[1];
	int			fd = open(PATH, O_RDONLY);
	int			result;
	char		**txt;

	(void)argc;
	if (fd < 0)
	{
		printf("the map didn't open 🫵 Looser !\n");
		return (-1);
	}
	txt = malloc (1 * sizeof(char *));
	txt[0] = NULL;
	txt = get_text(fd, txt);
	result = parsing(txt);

	free_all(txt);
}
