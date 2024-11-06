/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:55:34 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/25 09:57:12 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_dict
{
	char	key;
	int		(*value)(void *);
}			t_dict;

t_dict	*create(void);

void	*find(t_dict *dict, char c);

int		ft_pointer(void *ptr);

int		ft_putnbr(void *num);

int		ft_putunbr(void *num);

int		ft_hex_up(void *num);

int		ft_hex_low(void *num);

int		ft_putstr(void *s);

int		ft_putchar(void *c);

int		ft_printf(const char *s, ...);

#endif
