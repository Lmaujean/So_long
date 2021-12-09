/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:32:51 by lmaujean          #+#    #+#             */
/*   Updated: 2021/12/07 11:32:53 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_close(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(0);
}

t_img	*dir_player(int dir, t_game *game)
{
	if (dir == 1)
		return (&game->img[4]);
	else if (dir == 2)
		return (&game->img[2]);
	else if (dir == 3)
		return (&game->img[3]);
	else if (dir == 4)
		return (&game->img[5]);
	return (NULL);
}

static void	update_maps(t_game *game, t_pos pos, int dir)
{
	const int	x = game->player.x;
	const int	y = game->player.y;
	static int	move = 0;

	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->c--;
		mlx_put_img_to_img(&game->main, &game->img[1],
			pos.x * PXL, pos.y * PXL);
		mlx_put_img_to_img(&game->main, &game->img[1],
			x * PXL, y * PXL);
		mlx_put_img_to_img(&game->main, dir_player(dir, game),
				x * PXL, y * PXL);
	}
	else if (game->map[y][x] == '0')
	{
		mlx_put_img_to_img(&game->main, &game->img[1],
			pos.x * PXL, pos.y * PXL);
		mlx_put_img_to_img(&game->main, &game->img[1],
			x * PXL, y * PXL);
		mlx_put_img_to_img(&game->main, dir_player(dir, game),
				x * PXL, y * PXL);
	}
	else if (game->map[y][x] == '1' || (game->map[y][x] == 'E' && game->c != 0))
	{
		game->player = pos;
		mlx_put_img_to_img(&game->main, &game->img[1],
			pos.x * PXL, pos.y * PXL);
		mlx_put_img_to_img(&game->main, dir_player(dir, game),
				pos.x * PXL, pos.y * PXL);
	}
	else if (game->map[y][x] == 'E' && game->c == 0)
	{
		ft_free_game(game);
		printf("GG\n");
		ft_close(0, game);
	}
	if (game->player.x != pos.x || game->player.y != pos.y)
		printf("Move player : %d\n", ++move);

}

int	ft_press(int keycode, t_game *game)
{
	const t_pos	lastpos = game->player;
	int			dir;

	dir = 0;
	if (keycode == KEY_ECHAP)
	{
		ft_free_game(game);
		ft_close(0, game);
	}
	else if (keycode == KEY_A)
	{
		game->player.x--;
		dir = 1;
	}
	else if (keycode == KEY_S)
	{
		game->player.y++;
		dir = 2;
	}
	else if (keycode == KEY_D)
	{
		game->player.x++;
		dir = 3;
	}
	else if (keycode == KEY_W)
	{
		game->player.y--;
		dir = 4;
	}
	update_maps(game, lastpos, dir);
	mlx_put_image_to_window(game->init_mlx, game->init_window, \
		game->main.img, -800 * ((game->player.x * PXL) / 800),
		-800 * ((game->player.y * PXL) / 800));
	return (0);
}

// int	ft_cam_x(t_game *game)
// {
// 	if ()
// }

// int	ft_cam_y(t_game *game)
// {
// 	if ()
// }