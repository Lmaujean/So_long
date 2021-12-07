/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaujean <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:31:22 by lmaujean          #+#    #+#             */
/*   Updated: 2021/11/30 10:32:46 by lmaujean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/******* STRUC INIT MLX *******/

typedef struct s_img
{
	void	*init_mlx;
	void	*init_window;
	void	*img;
	int		wind_h;
	int		wind_l;
}			t_img;

typedef struct s_game
{
	char	**map;
	int		x;
	int		y;
	int		p;
	int		c;
	int		e;
	int		wall;
	int		space;
}			t_game;

/******* FONCTION UTILS *******/

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		get_next_line(int fd, char **line);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
void	ft_free_exit(char **ptr);

/******* FONCTION PARSING *******/

int		ft_pars_ber(int ac, char **av);
void	ft_init_minilibx(t_img init);
int		ft_valid_fd(char *av, int ac);
int		ft_check_map(int fd);
void	ft_get_map(int fd, char *av, t_game *maps);
void	ft_init_struc(t_game *maps);
void	ft_pars_map(t_game *maps);
void	ft_error_map(t_game *maps);
void	ft_check_wall(char **str, int x, int y);
void	ft_check_y(char **str, int x, int y);
void	ft_check_rectangular(char **str);
void	map(t_img *img, int y, int x);

#endif
