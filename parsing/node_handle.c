/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:49:40 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/07 13:47:17 by cmorel           ###   ########.fr       */
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

int	check_truth(t_checks *check)
{
	int	i;

	i = 0;
	while (check[i].key != '\0')
	{
		if (check[i].value == 0)
			return (0);
		i++;
	}
	return (1);
}


t_checks	*ft_find(t_checks *dict, char c)
{
	int	i;

	i = 0;
	while (dict[i].key != '\0' && dict[i].key != c)
		i++;
	if (dict[i].key != c)
		return (NULL);
	return (&dict[i]);
}

t_checks	*ft_create(void)
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
