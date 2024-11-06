/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:09 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/25 09:56:30 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	error_handling(int error, va_list chain)
{
	if (error == 1)
	{
		write(2, "ERROR: UNDEFINED %\n", 19);
		va_end(chain);
		return (-1);
	}
	else if (error == 2)
	{
		return (-1);
	}
	else if (error == 3)
	{
		va_end(chain);
	}
	return (0);
}

// int --> void * (int) --> void * (int *) --> int * --> int
static int	ft_check(char c, va_list chain)
{
	int		len;
	int		(*fct)(void *);
	void	*tmp;
	t_dict	*dict;

	dict = create();
	fct = find(dict, c);
	len = -1;
	if (fct)
	{
		tmp = va_arg(chain, void *);
		len = fct(&tmp);
	}
	else
		error_handling(1, chain);
	free(dict);
	return (len);
}

int	tester(char *s, va_list chain, int *i)
{
	int	check;

	check = 0 ;
	if (s[*i] == '%')
	{
		(*i)++;
		if (s[*i] == '%')
			check = write(1, "%", 1);
		else
			check = ft_check(s[*i], chain);
	}
	else
		check = write(1, &s[*i], 1);
	return (check);
}

int	ft_printf(const char *s, ...)
{
	va_list	chain;
	int		len;
	int		check;
	int		i;

	i = 0;
	if (!s)
		return (error_handling(2, NULL));
	va_start(chain, s);
	len = 0;
	while (s[i])
	{
		check = tester((char *)s, chain, &i);
		if (check == -1)
			return (-1);
		i++;
		len += check;
	}
	error_handling(3, chain);
	return (len);
}
