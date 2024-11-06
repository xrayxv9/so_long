/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:23:42 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/25 09:55:26 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putlnbr(size_t n, char *base)
{
	if (n > 15)
	{
		return (ft_putlnbr(n / 16, base) + ft_putlnbr(n % 16, base));
	}
	else
	{
		write(1, &base[n], 1);
		return (1);
	}
}

// (unsigned long long)p == 0
int	ft_pointer(void *ptr)
{
	size_t	p;

	p = *((size_t *)ptr);
	if (p == 0)
	{
		return (write(1, "(nil)", 5));
	}
	else
	{
		return (write(1, "0x", 2)
			+ ft_putlnbr(p, "0123456789abcdef"));
	}
}
