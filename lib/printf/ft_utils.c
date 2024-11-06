/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:25:11 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/25 09:51:46 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(void *c)
{
	char	ch;

	ch = *((char *)c);
	write(1, &ch, 1);
	return (1);
}

int	ft_putstr(void *s)
{
	int		i;
	char	*str;

	i = 0;
	str = *((char **)s);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
