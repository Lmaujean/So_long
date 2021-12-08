/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:16:24 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/30 17:16:48 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	ft_choose_img(t_game *game, int x, int y)
// {
// 	if (game->map[y][x] == '1')
// 		game->img->img = mlx_xpm_file_to_image(game->init_mlx, WALL1, \
// 		game->img->width, game->img->height);
// 	else if (game->map[y][x] == '0')
// 		game->img->img = mlx_xpm_file_to_image(game->init_mlx, FLOOR, \
// 		game->img->width, game->img->height);
// 	else if (game->map[y][x] == 'P')
// 		game->img->img = mlx_xpm_file_to_image(game->init_mlx, PLAYER_RIGHT1, \
// 		game->img->width, game->img->height);
// 	else if (game->map[y][x] == 'C')
// 		game->img->img = mlx_xpm_file_to_image(game->init_mlx, COLLEC, \
// 		game->img->width, game->img->height);
// 	else if (game->map[y][x] == 'E')
// 		game->img->img = mlx_xpm_file_to_image(game->init_mlx, EXIT, \
// 		game->img->width, game->img->height);
// }

void	ft_size_window(t_game *game)
{
	if (game->line.x * PXL > DEF_L)
		game->wind.x = DEF_L;
	else
		game->wind.x = game->line.x * PXL;
	if (game->line.y * PXL > DEF_H)
		game->wind.y = DEF_H;
	else
		game->wind.y = game->line.y * PXL;
}

int	ft_init_img(t_game *game)
{
	int	i;

	i = 0;
	game->img = malloc(sizeof(t_img) * NBR_IMG);
	if (!game->img)
	{
		return (0);
	}
	while (i < NBR_IMG)
	{
		game->img[i].img = NULL;
		game->img[i].img = mlx_xpm_file_to_image(game->init_mlx, PLAYER_FACE1, &game->img[i].width, &game->img[i].height);
		create_img(&game->img[i], game->img[i].img);
		game->img[i].width = PXL;
		game->img[i].height = PXL;
		i++;
	}
	return (1);
}

int	ft_init_minilibx(t_game *game)
{
	ft_size_window(game);
	game->init_mlx = NULL;
	game->init_window = NULL;
	game->init_mlx = mlx_init();
	if (!game->init_mlx)
		return (0);
	game->init_window = mlx_new_window(game->init_mlx, game->wind.x, \
										game->wind.y, "So_long");
	if (!game->init_window)
		return (0);
	if (ft_init_img(game) == 0)
		return (0);
	return (1);
}



void	ft_init_struc(t_game *maps)
{
	maps->line.y = 1;
	maps->line.x = 0;
	maps->p = 0;
	maps->c = 0;
	maps->e = 0;
}
