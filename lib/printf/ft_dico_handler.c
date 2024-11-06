/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dico_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:49:40 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/25 09:51:06 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static t_dict	node_maker(char c, int (*fct)(void *))
{
	t_dict	node;

	node.key = c;
	node.value = *fct;
	return (node);
}

void	*find(t_dict *dict, char c)
{
	int	i;

	i = 0;
	while (dict[i].key && dict[i].key != c)
		i++;
	return (dict[i].value);
}

t_dict	*create(void)
{
	t_dict	*dict;

	dict = malloc(9 * sizeof(t_dict));
	dict[8] = node_maker('\0', NULL);
	dict[0] = node_maker('c', ft_putchar);
	dict[1] = node_maker('s', ft_putstr);
	dict[2] = node_maker('p', ft_pointer);
	dict[3] = node_maker('d', ft_putnbr);
	dict[4] = node_maker('i', ft_putnbr);
	dict[5] = node_maker('u', &ft_putunbr);
	dict[6] = node_maker('x', ft_hex_low);
	dict[7] = node_maker('X', ft_hex_up);
	return (dict);
}
