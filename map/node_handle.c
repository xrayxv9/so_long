/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:49:40 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/24 17:13:06 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static t_checks	node_maker(char c)
{
	t_checks	node;

	node.key = c;
	node.value = 0;
	return (node);
}

t_checks	*find(t_checks *dict, char c)
{
	int	i;

	i = 0;
	while (dict[i].key != -1 && dict[i].key != c)
		i++;
	if (dict[i].key != c)
		return (NULL);
	return (&dict[i]);
}

t_checks	*create(void)
{
	t_checks	*dict;

	dict = malloc(6 * sizeof(t_checks));
	dict[5] = node_maker('\0');
	dict[0] = node_maker('C' );
	dict[1] = node_maker('0');
	dict[2] = node_maker('1');
	dict[3] = node_maker('P');
	dict[4] = node_maker('E');
	dict[5].value = -1;
	return (dict);
}
