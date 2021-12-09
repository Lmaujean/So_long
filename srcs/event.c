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

static t_img	*dir_p(int dir, t_game *game)
{
	if (dir == KEY_A)
		return (&game->img[4]);
	else if (dir == KEY_S)
		return (&game->img[2]);
	else if (dir == KEY_D)
		return (&game->img[3]);
	else if (dir == KEY_W)
		return (&game->img[5]);
	return (NULL);
}

static void	update_maps(t_game *game, t_pos p, int dir)
{
	const int	x = game->player.x;
	const int	y = game->player.y;

	if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		if (game->map[y][x] == 'C')
		{
			game->map[y][x] = '0';
			game->c--;
		}
		mlx_put_img_to_img(&game->main, &game->img[1], p.x * PXL, p.y * PXL);
		mlx_put_img_to_img(&game->main, &game->img[1], x * PXL, y * PXL);
		mlx_put_img_to_img(&game->main, dir_player(dir, game), x * PXL,
			y * PXL);
	}
	else if (game->map[y][x] == '1' || (game->map[y][x] == 'E' && game->c != 0))
	{
		game->player = pos;
		mlx_put_img_to_img(&game->main, &game->img[1], p.x * PXL, p.y * PXL);
		mlx_put_img_to_img(&game->main, dir_p(dir, game), p.x * PXL, p.y * PXL);
	}
	else if (game->map[y][x] == 'E' && game->c == 0)
		ft_press(KEY_ECHAP, game);
	if (game->player.x != p.x || game->player.y != p.y)
		printf("Move player : %d\n", ++game->move);
}

int	ft_press(int keycode, t_game *game)
{
	const t_pos	lastpos = game->player;

	if (keycode == KEY_ECHAP)
	{
		ft_free_game(game);
		ft_close(0, game);
	}
	else if (keycode == KEY_A)
		game->player.x--;
	else if (keycode == KEY_S)
		game->player.y++;
	else if (keycode == KEY_D)
		game->player.x++;
	else if (keycode == KEY_W)
		game->player.y--;
	if (keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_W)
	{
		update_maps(game, lastpos, keycode);
		mlx_put_image_to_window(game->init_mlx, game->init_window,
			game->img[8].img, 0, 0);
		mlx_put_image_to_window(game->init_mlx, game->init_window,
			game->main.img, ft_cam_x(game), ft_cam_y(game));
	}
	return (0);
}
