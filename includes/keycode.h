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

#ifndef MLX_KEYCODE_H
# define MLX_KEYCODE_H

# define WALL1 "../xpmfile/wall/wall1.xpm"
# define WALL2 "../xpmfile/wall/wall2.xpm"
# define FLOOR "../xpmfile/floor/floor.xpm"
# define PLAYER_FACE1 "xpmfile/player_face/down_1.xpm"
# define PLAYER_FACE2 "../xpmfile/player/player_face/player_face2.xpm"
# define PLAYER_FACE3 "../xpmfile/player/player_face/player_face3.xpm"
# define PLAYER_RIGHT1 "../xpmfile/player/player_right/player_right1.xpm"
# define PLAYER_RIGHT2 "../xpmfile/player/player_right/player_right2.xpm"
# define PLAYER_RIGHT3 "../xpmfile/player/player_right/player_right3.xpm"
# define PLAYER_LEFT1 "../xpmfile/player/player_left/player_left1.xpm"
# define PLAYER_LEFT2 "../xpmfile/player/player_left/player_left2.xpm"
# define PLAYER_LEFT3 "../xpmfile/player/player_left/player_left3.xpm"
# define PLAYER_BACK1 "../xpmfile/player/player_back/player_back1.xpm"
# define PLAYER_BACK2 "../xpmfile/player/player_back/player_back2.xpm"
# define PLAYER_BACK3 "../xpmfile/player/player_back/player_back3.xpm"
# define COLLEC "../xpmfile/collec/collec.xpm"
# define PXL 64
# define DEF_H 800 /*hauteur*/
# define DEF_L 800 /*largeur*/
# define NBR_IMG 3



# ifdef __linux__
#  define KEY_Q 113
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_ECHAP 65307
# elif __APPLE__
#  define KEY_Q 12
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ECHAP 53
# endif

#endif