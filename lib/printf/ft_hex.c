/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:18:52 by cmorel            #+#    #+#             */
/*   Updated: 2024/11/12 18:49:00 by xray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	gen_hex(char *base, unsigned int num)
{
	if (num > 15)
	{
		return (gen_hex(base, num / 16) + gen_hex(base, num % 16));
	}
	else
	{
		ft_putchar(&base[num]);
		return (1);
	}
}

int	ft_hex_low(void *i)
{
	unsigned int	num;
	unsigned int	n;
	char			*base;

	base = "0123456789abcdef";
	num = *((unsigned int *)i);
	n = (unsigned int)num;
	return (gen_hex(base, n));
}

int	ft_hex_up(void *i)
{
	unsigned int	num;
	unsigned int	n;
	char			*base;

	base = "0123456789ABCDEF";
	num = *((unsigned int *)i);
	n = (unsigned int)-num;
	return (gen_hex(base, n));
}
