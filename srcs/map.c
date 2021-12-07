/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:01:10 by lmaujean          #+#    #+#             */
/*   Updated: 2021/12/06 12:01:12 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	close(fd);
	ft_check_rectangular(maps->map);
}

void	ft_pars_map(t_game *maps)
{
	int	i;
	int	j;

	i = -1;
	while (maps->map[++i])
	{
		j = -1;
		while (maps->map[i][++j])
		{
			if (maps->map[i][j] != 'C' && maps->map[i][j] != 'P' && \
				maps->map[i][j] != '0' && maps->map[i][j] != 'E' && \
				maps->map[i][j] != '1')
			{
				ft_putstr_fd("Error:\nInvalid Caractere On Map\n", 1);
				ft_free_exit(maps->map);
			}
			if (maps->map[i][j] == 'P')
				maps->p++;
			else if (maps->map[i][j] == 'E')
				maps->e++;
			else if (maps->map[i][j] == 'C')
				maps->c++;
		}
	}
}

void	ft_stock_wall_space(t_game *maps)
{
	int	i;
	int	j;

	i = -1;
	while (maps->map[++i])
	{
		j = -1;
		while (maps->map[i][++j])
		{
			if (maps->map[i][j] == '1')
				maps->wall++;
			else if (maps->map[i][j] == '0')
				maps->space++;
		}
	}
}

void	ft_error_map(t_game *maps)
{
	ft_pars_map(maps);
	ft_stock_wall_space(maps);
	if (maps->p < 1 || maps->p > 1)
	{
		ft_putstr_fd("Error:\nWTF Bro need  Just 1 player !!\n", 1);
		ft_free_exit(maps->map);
	}
	if (maps->c < 1)
	{
		ft_putstr_fd("Error:\nWTF Bro Need At Least One Collectible\n", 1);
		ft_free_exit(maps->map);
	}
	if (maps->e < 1)
	{
		ft_putstr_fd("Error:\nWTF Bro Need At Least One Exit\n", 1);
		ft_free_exit(maps->map);
	}
}
