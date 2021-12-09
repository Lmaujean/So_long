/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:45 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/30 13:13:24 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# define WALL1 "xpmfile/wall/wall.xpm"
# define FLOOR "xpmfile/floor/floor.xpm"
# define PLAYER_FACE1 "xpmfile/player_face/down_1.xpm"
# define PLAYER_RIGHT1 "xpmfile/player_right/right.xpm"
# define PLAYER_LEFT1 "xpmfile/player_left/left_1.xpm"
# define PLAYER_BACK1 "xpmfile/player_back/up.xpm"
# define COLLEC "xpmfile/collec/collect.xpm"
# define EXIT "xpmfile/exit/Exit.xpm"
# define PXL 64
# define DEF_H 800 /*hauteur*/
# define DEF_L 800 /*largeur*/
# define NBR_IMG 8

# ifdef __linux__
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ECHAP 65307
# elif __APPLE__
#  define KEY_A 0
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ECHAP 53
# endif

#endif