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

void	ft_init_minilibx(t_img init)
{
	init.init_mlx = mlx_init();
	init.init_window = mlx_new_window(init.init_mlx, init.wind_h, init.wind_l, \
					"So_long");
	mlx_loop(init.init_mlx);
}

void	ft_init_struc(t_game *maps)
{
	maps->y = 1;
	maps->x = 0;
	maps->p = 0;
	maps->c = 0;
	maps->e = 0;
}

/* mlx_put_image_to_window(init.init_mlx, init.init_window, init.img, \
							0, 0);
	mlx_loop(init.init_mlx);
	init.img = mlx_xpm_file_to_image(init.init_mlx, "../test.xpm", \
									&init.wind_h, &init.wind_l); */