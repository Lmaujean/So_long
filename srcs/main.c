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
	t_img	img;
	int		i;

	i = 0;
	ft_init_struc(&maps);
	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_pars_ber(ac, av);
		ft_get_map(fd, av[1], &maps);
		ft_error_map(&maps);
		ft_check_wall(maps.map, maps.x, maps.y);
		map(&img, maps.y, maps.x);
		ft_init_minilibx(img);
		close(fd);
	}
	return (0);
}
