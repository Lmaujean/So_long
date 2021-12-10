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

void	launch_game(t_game *game)
{
	game->main.img = mlx_new_image(game->init_mlx, game->line.x * PXL, \
									game->line.y * PXL);
	create_img(&game->main, game->main.img);
	game->main.height = game->line.y * PXL;
	game->main.width = game->line.x * PXL;
	ft_choose_img(game);
	mlx_put_img_to_img(&game->main, &game->img[3],
		game->player.x * PXL, game->player.y * PXL);
	if (game->line.x > DEF_L)
		mlx_put_image_to_window(game->init_mlx, game->init_window,
			game->img[8].img, 0, 0);
	mlx_put_image_to_window(game->init_mlx, game->init_window, game->main.img,
		ft_cam_x(game), ft_cam_y(game));
	mlx_hook(game->init_window, 17, 0, ft_close, game);
	mlx_hook(game->init_window, 2, 1L << 0, ft_press, game);
	mlx_loop(game->init_mlx);
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	game.move = 0;
	ft_init_struc(&game);
	fd = ft_valid_fd(av[1], ac);
	if (fd)
	{
		ft_pars_ber(ac, av);
		ft_get_map(fd, av[1], &game);
		ft_error_map(&game);
		ft_check_wall(game.map, game.line.x, game.line.y);
		close(fd);
		if (!ft_init_minilibx(&game))
		{
			printf("Error:\n");
			ft_free_game(&game);
			exit(EXIT_FAILURE);
		}
		launch_game(&game);
	}
	return (0);
}
