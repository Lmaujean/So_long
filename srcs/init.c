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

void	init_minilibx(void)
{
	t_init	init;

	init.init_mlx = mlx_init();
	init.init_window = mlx_new_window(init.init_mlx, 500, 500, "So_long");
	mlx_loop(init.init_mlx);
}
