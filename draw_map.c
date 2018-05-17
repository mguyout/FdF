/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:07:57 by mguyout           #+#    #+#             */
/*   Updated: 2017/04/07 20:40:28 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	draw_right(t_struct *env, int w, int w2)
{
	env->y1 = env->y0 - env->uy - ((w2 * env->uy) * env->size);
	line(env->x0, env->y0 - ((w * env->uy) * env->size),
	env->x0 + env->ux, env);
}

void	draw_left(t_struct *env, int w, int w2)
{
	env->y1 = env->y0 - env->uy - ((w2 * env->uy) * env->size);
	line(env->x0, env->y0 - ((w * env->uy) * env->size),
	env->x0 - env->ux, env);
}

void	get_value(int ux, t_struct *env)
{
	env->z = -1;
	env->x0 = (env->y == env->x) ? env->length / 2 + env->mx :
(env->length / 2) - (((env->x) * ux) / 2) + (((env->y) * ux) / 2) + env->mx;
	env->y0 = env->height - 1 + env->my;
}

void	draw_core(int ux, int uy, int **map, t_struct *env)
{
	int i;

	i = -1;
	get_value(ux, env);
	while (++env->z < env->y)
	{
		env->savex = env->x0 - ux;
		env->savey = env->y0 - uy;
		i = -1;
		while (++i < env->x)
		{
			env->ux = ux;
			env->uy = uy;
			if (env->z < env->y - 1)
				draw_left(env, map[env->s][i], map[env->s - 1][i]);
			if (i < env->x - 1)
				draw_right(env, map[env->s][i], map[env->s][i + 1]);
			env->x0 = env->x0 + ux;
			env->y0 = env->y0 - uy;
		}
		env->s--;
		env->x0 = env->savex;
		env->y0 = env->savey;
	}
}

void	draw(t_struct *env, int **map)
{
	int y;
	int i;
	int ux;
	int uy;

	env->s = env->y - 1;
	i = -1;
	env->length = 2560;
	env->height = 1315;
	y = map[0][env->x - 1] * env->size;
	while (++i < env->y)
	{
		env->z = -1;
		while (++env->z < env->x)
			if ((map[i][env->z] * env->size - (env->x - env->z + i - 1) > y))
				y = (map[i][env->z] * env->size - (env->x - env->z + i - 1));
	}
	y = (y < 0) ? -y : y;
	uy = env->y + env->x - 1;
	while (uy * (env->height / (uy + y)) > env->height)
		uy = uy - 1;
	uy = (uy < 0) ? -uy : uy;
	uy = env->height / (uy + y) - env->mz;
	ux = uy * 2;
	draw_core(ux, uy, map, env);
}
