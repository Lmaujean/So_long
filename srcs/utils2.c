/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:16:43 by lmaujean          #+#    #+#             */
/*   Updated: 2021/12/01 10:16:46 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	i = 0;
	while (i != size * count)
	{
		str[i] = 0;
		i++;
	}	
	return (str);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (word);
}

static char	*strdupcpy(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = ft_calloc(sizeof(char), i + 1);
	if (!str)
		return (0);
	i = 0;
	while (*s != c && *s)
	{
		str[i] = *s;
		s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**kherz;
	int		i;
	int		n;

	if (!s)
		return (0);
	n = count_word(s, c);
	kherz = ft_calloc(sizeof(char *), (count_word((char *)s, c) + 1));
	if (!kherz)
		return (0);
	i = 0;
	while (i < n)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			kherz[i] = strdupcpy((char *)s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	return (kherz);
}

void	ft_free_exit(char **ptr)
{
	int	i;

	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = 0;
			i++;
		}
		free(ptr);
		ptr = 0;
		exit(EXIT_FAILURE);
	}
}
