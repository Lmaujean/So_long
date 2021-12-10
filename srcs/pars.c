/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:10:33 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/30 15:10:53 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_pars_ber(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = ft_strchr(av[1], 46);
		if (str && !ft_strcmp(str, ".ber"))
			return (1);
		else
		{
			ft_putstr_fd("Error:\n'.ber' Invalid\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("Error:\nFile Not '.ber'\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_valid_fd(char *str, int ac)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Error:\nArgument Not Valid\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error:\nTry Open Directory\n", 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error:\nWrong File\n", 1);
		close(fd);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_check_y(char **str, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && str[i][x - 1] && i < y)
	{
		while (str[i][j] != '1' || str[i][x - 1] != '1')
		{
			ft_putstr_fd("Error:\nMap Not Closed\n", 1);
			ft_freedouble(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_check_rectangular(char **str)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(str[i]);
	while (str[i])
	{
		if (ft_strlen(str[i]) != 0 && j != ft_strlen(str[i]))
		{
			ft_putstr_fd("Error:\nMap Not Rectangular\n", 1);
			ft_freedouble(str);
			exit(EXIT_FAILURE);
		}
		if (ft_strlen(str[i]) == 0 && str[i + 1] && ft_strlen(str[i + 1]) == 0)
		{
			ft_putstr_fd("Error:\nMap Not Valid\n", 1);
			ft_freedouble(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	ft_check_wall(char **str, int x, int y)
{
	int	i;

	i = 0;
	while ((str[0][i] && str[y - 1][i] && i < x) || (str[0][i] \
		&& str[y - 1][i] == '\0' && x == 0))
	{
		if (str[0][i] != '1' || str[y - 1][i] != '1')
		{
			ft_putstr_fd("Error:\nMap Not Closed\n", 1);
			ft_freedouble(str);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_check_y(str, x, y);
}
