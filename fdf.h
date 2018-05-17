/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:27:37 by mguyout           #+#    #+#             */
/*   Updated: 2018/05/17 17:25:05 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "Libft/libft.h"

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	char		*tab;
	void		*im;
	int			x;
	int			y;
	int			height;
	int			length;
	int			savex;
	int			savey;
	int			width;
	double		size;
	int			**map;
	int			bits;
	int			line;
	int			endian;
	int			pos;
	int			ux;
	int			uy;
	int			err;
	int			e2;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			check;
	int			mx;
	int			my;
	int			mz;
	int			ret;
	int			s;
	int			z;
	int			x0;
	int			y0;
	int			m;
}				t_struct;
int				**ft_realloc(int **map, char *line, t_struct *env);
void			free_map(t_struct *env, int **map);
void			draw_right(t_struct *env, int width, int width2);
void			draw_left(t_struct *env, int width, int width2);
void			line(int x0, int y0, int x1, t_struct *env);
void			draw(t_struct *env, int **map);
int				**create_map(int fd, char **argv, t_struct *env);
int				**create_line(int **map, t_struct *env, char *line);
int				check_map(int fd, t_struct *env);
int				get_next_line(int fd, char **stock);
int				hook_main(int keycode, t_struct *env);
#endif
