/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 20:57:00 by mguyout           #+#    #+#             */
/*   Updated: 2018/05/17 17:25:24 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void	put_pixel(int x0, int y0, t_struct *env)
{
	env->pos = (x0 * 4) + ((env->line * y0));
	env->tab[env->pos] = (char)255;
	env->tab[env->pos + 1] = (char)255;
	env->tab[env->pos + 2] = (char)255;
	env->tab[env->pos + 3] = 0;
}

void	line(int x0, int y0, int x1, t_struct *env)
{
	if ((env->dx = x1 - x0) < 0)
		env->dx = -env->dx;
	env->sx = (x0 < x1) ? 1 : -1;
	if ((env->dy = env->y1 - y0) < 0)
		env->dy = -env->dy;
	env->sy = (y0 < env->y1) ? 1 : -1;
	env->err = ((env->dx > env->dy) ? env->dx : -env->dy) / 2;
	while (1)
	{
		if (y0 < 1315 && y0 > 0 && x0 > 0 && x0 < 2560)
			put_pixel(x0, y0, env);
		if (x0 == x1 && y0 == env->y1)
			break ;
		env->e2 = env->err;
		if (env->e2 > -env->dx)
		{
			env->err -= env->dy;
			x0 += env->sx;
		}
		if (env->e2 < env->dy)
		{
			env->err += env->dx;
			y0 += env->sy;
		}
	}
}

void	free_map(t_struct *env, int **map)
{
	int i;

	i = -1;
	while (++i < env->y)
		free(map[i]);
	free(env);
}

int		main(int argc, char **argv)
{
	t_struct	*env;

	if ((argc != 2 || !(env = (t_struct*)malloc(sizeof(t_struct))) ||
!(env->map = create_map(open(argv[1], O_RDONLY), argv, env))))
	{
		ft_putstr("\033[1;31mErreur\n\033[0m");
		return (0);
	}
	env->mlx = mlx_init();
	mlx_do_key_autorepeaton(env->mlx);
	env->size = 1;
	env->mx = 0;
	env->my = 0;
	env->m = 5;
	env->win = mlx_new_window(env->mlx, 2560, 1315, argv[1]);
	env->im = mlx_new_image(env->mlx, 2560, 1315);
	env->tab = mlx_get_data_addr(env->im, &env->bits, &env->line, &env->endian);
	draw(env, env->map);
	mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	mlx_hook(env->win, 2, 0, hook_main, env);
	mlx_loop(env->mlx);
	free_map(env, env->map);
	mlx_destroy_image(env->mlx, env->im);
	mlx_destroy_window(env->mlx, env->win);
	return (0);
}
