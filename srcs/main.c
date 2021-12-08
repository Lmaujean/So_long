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
	t_game	game;
	int	i;
	int j;

	i = 0;
	ft_init_struc(&game);
	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_pars_ber(ac, av);
		ft_get_map(fd, av[1], &game);
		ft_error_map(&game);
		ft_check_wall(game.map, game.line.x, game.line.y);
		if (!ft_init_minilibx(&game))
		{
			printf("Error:\n");
			ft_free_game(&game);
			exit(EXIT_FAILURE);
		}
		if (game.img[0].img)
		{
			while (game.map[i])
			{
				j = 0;
				while(game.map[i][j])
				{
					mlx_put_image_to_window(game.init_mlx, game.init_window, game.img[0].img, j * PXL, i * PXL);
					j++;
				}
				i++;

			}
			mlx_loop(game.init_mlx);
		}
		else
			printf("img bug vaut NULL\n");
		close(fd);
	}
	return (0);
}
