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

void	ft_get_map(int fd, char *av, t_game *maps)
{
	char	*line;
	int		i;

	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		maps->y++;
		free(line);
	}
	free(line);
	maps->map = malloc(sizeof(char *) * (maps->y + 1));
	i = -1;
	fd = open(av, O_RDONLY);
	i = -1;
	while (++i < maps->y)
	{
		get_next_line(fd, &line);
		maps->map[i] = ft_strdup(line);
		maps->x = ft_strlen(line);
		free(line);
	}
	maps->map[i] = 0;
}


void	ft_pars_map(t_game *maps)
{
	int	i;
	int	j;

	i = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == 'P')
				maps->p++;
			else if (maps->map[i][j] == 'E')
				maps->e++;
			else if (maps->map[i][j] == 'C')
				maps->c++;
			j++;
		}
		i++;
	}
}

void	ft_error_map(t_game *maps)
{
	ft_pars_map(maps);
	if (maps->p < 1 || maps->p > 1)
	{
		ft_putstr_fd("Error : WTF Bro need  Just 1 player !!\n", 1);
		exit(EXIT_FAILURE);
	}
	if (maps->c < 1)
	{
		ft_putstr_fd("Error : WTF Bro Need At Least One Collectible\n", 1);
		exit(EXIT_FAILURE);
	}
	if (maps->e < 1)
	{
		ft_putstr_fd("Error : WTF Bro Need At Least One Exit\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_x(char **str, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (str[0][i] && str[y - 1][i] && i < x)
	{
		if (str[0][i] != '1' || str[y - 1][i] != '1')
		{
			ft_putstr_fd("Error : Map Not Closed\n", 1);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (str[i] && str[i][x - 1] && i < y)
	{
		while (str[i][j] != '1' || str[i][x - 1] != '1')
		{
			ft_putstr_fd("Error : Map Not Closed\n", 1);
			exit(EXIT_FAILURE);
			j++;
		}
		i++;
	}
}
