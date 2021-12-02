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
			ft_putstr_fd("Error : '.ber' Invalid\n", 1);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_putstr_fd("Error : File Not '.ber'\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_valid_fd(char *str, int ac)
{
	int	fd;

	if (ac != 2)
	{
		ft_putstr_fd("Error : Argument Not Valid\n", 1);
		exit(EXIT_FAILURE);
	}
	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error : Try Open Directory\n", 1);
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error : Wrong File\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_get_map(int fd, char *av)
{
	int		count;
	char	*line;
	char	**tab;
	int		i;

	line = NULL;
	count = 1;
	tab = NULL;
	while ((get_next_line(fd, &line)) == 1)
	{
		count++;
		free(line);
	}
	tab = malloc(sizeof(char **) * count + 1);
	fd = open(av, O_RDONLY);
	i = 0;
	while (i < count)
	{
		get_next_line(fd, &line);
		tab[i] = ft_strdup(line);
		i++;
		free(line);
	}
}
