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
	int	fd;

	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_pars_ber(ac, av);
		ft_get_map(fd, av[1]);
		//init_minilibx();
	}
	return (0);
}
