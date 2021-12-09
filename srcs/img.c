/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:11:36 by lmaujean          #+#    #+#             */
/*   Updated: 2021/12/09 14:11:37 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_choose_img(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			mlx_put_img_to_img(&game->main, &game->img[1], x * PXL, y * PXL);
			if (game->map[y][x] == '1')
				mlx_put_img_to_img(&game->main, &game->img[0],
					x * PXL, y * PXL);
			else if (game->map[y][x] == 'C')
				mlx_put_img_to_img(&game->main, &game->img[6],
					x * PXL, y * PXL);
			else if (game->map[y][x] == 'E')
				mlx_put_img_to_img(&game->main, &game->img[7],
					x * PXL, y * PXL);
		}
	}
}

int	ft_cam_x(t_game *game)
{
	const int	calc = -800 * ((game->player.x * PXL) / 800);

	return (calc);
}

int	ft_cam_y(t_game *game)
{
	const int	calc = -800 * ((game->player.y * PXL) / 800);

	return (calc);
}
