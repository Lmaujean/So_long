/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:01:51 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/30 11:05:24 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	maps;
	int		i;

	i = 0;
	ft_init_struc(&maps);
	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_pars_ber(ac, av);
		ft_get_map(fd, av[1], &maps);
		ft_check_x(maps.map, maps.x, maps.y);
		//ft_check_y(maps.map, maps.x, maps.y);
		//printf("%d\n", maps.y);
		while (maps.map[i])
		{
			printf("%s\n", maps.map[i]);
			i++;
		}
		if (ac == 2)
			close(fd);
		//init_minilibx();
	}
	return (0);
}
