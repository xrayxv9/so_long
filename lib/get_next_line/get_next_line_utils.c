/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel <cmorel@42angouleme.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:05:46 by cmorel            #+#    #+#             */
/*   Updated: 2024/10/24 17:29:12 by cmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*t;
	int		len;
	int		len2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	t = malloc((len + len2 + 1) * sizeof(char));
	if (!t)
		return (NULL);
	i = 0;
	while (len > i)
	{
		t[i] = s1[i];
		i++;
	}
	while (len2 + len > i)
	{
		t[i] = *(s2++);
		i++;
	}
	t[len + len2] = '\0';
	return (t);
}

int	ft_strchr(char c, char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mal;
	size_t	i;

	i = 0;
	if (size == 0 || nmemb == 0)
	{
		mal = malloc(0);
		return (mal);
	}
	mal = malloc(nmemb * size);
	if (!mal)
		return (NULL);
	while (size * nmemb > i)
	{
		((char *)mal)[i] = '\0';
		i++;
	}
	return (mal);
}

char	*ft_strdup(char *s)
{
	size_t		len;
	int			i;
	char		*dup;

	i = 0;
	len = ft_strlen(s);
	dup = malloc((1 + len) * sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
