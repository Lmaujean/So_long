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
		maps->line.y++;
		free(line);
	}
	free(line);
	maps->map = malloc(sizeof(char *) * (maps->line.y + 1));
	fd = open(av, O_RDONLY);
	i = -1;
	while (++i < maps->line.y)
	{
		get_next_line(fd, &line);
		maps->map[i] = ft_strdup(line);
		maps->line.x = ft_strlen(line);
		free(line);
	}
	maps->map[i] = 0;
	close(fd);
	ft_check_rectangular(maps->map);
}

void	ft_player(t_game *maps, int i, int j)
{
	maps->map[i][j] = '0';
	maps->player.x = j;
	maps->player.y = i;
	maps->p++;
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
				ft_freedouble(maps->map);
				exit(EXIT_FAILURE);
			}
			if (maps->map[i][j] == 'P')
				ft_player(maps, i, j);
			else if (maps->map[i][j] == 'E')
				maps->e++;
			else if (maps->map[i][j] == 'C')
				maps->c++;
		}
	}
}

void	ft_error_map(t_game *maps)
{
	ft_pars_map(maps);
	if (maps->p < 1 || maps->p > 1)
	{
		ft_putstr_fd("Error:\nWTF Bro need  Just 1 player !!\n", 1);
		ft_freedouble(maps->map);
		exit(EXIT_FAILURE);
	}
	if (maps->c < 1)
	{
		ft_putstr_fd("Error:\nWTF Bro Need At Least One Collectible\n", 1);
		ft_freedouble(maps->map);
		exit(EXIT_FAILURE);
	}
	if (maps->e < 1)
	{
		ft_putstr_fd("Error:\nWTF Bro Need At Least One Exit\n", 1);
		ft_freedouble(maps->map);
		exit(EXIT_FAILURE);
	}
}
