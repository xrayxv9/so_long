/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:46:35 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/24 15:18:13 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put(unsigned int n, char *base)
{
	if (n > 9)
	{
		return (ft_put(n / 10, base) + ft_put(n % 10, base));
	}
	else
	{
		n = n % 10;
		write(1, &base[n], 1);
		return (1);
	}
}

int	ft_putnbr(void *num)
{
	int				i;
	int				len;
	unsigned int	n;

	i = *((int *)num);
	len = 0;
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
		len++;
	}
	n = (unsigned int)i;
	len += ft_put(i, "0123456789");
	return (len);
}

int	ft_putunbr(void *num)
{
	unsigned int	n;
	unsigned int	i;
	int				len;

	i = *((unsigned int *)num);
	if (i < 0)
		n = (unsigned int)(i * -1);
	else
		n = (unsigned int)i;
	len = ft_put(n, "0123456789");
	return (len);
}
