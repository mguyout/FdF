/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 05:11:50 by mguyout           #+#    #+#             */
/*   Updated: 2017/04/07 20:41:18 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

void	directional_move(int keycode, t_struct *env)
{
	if (keycode == 124 || keycode == 123)
	{
		env->mx = (keycode == 124) ? env->mx + env->m : env->mx - env->m;
		mlx_destroy_image(env->mlx, env->im);
		env->im = mlx_new_image(env->mlx, 2560, 1315);
		draw(env, env->map);
		mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	}
	if (keycode == 125 || keycode == 126)
	{
		env->my = (keycode == 125) ? env->my + env->m : env->my - env->m;
		mlx_destroy_image(env->mlx, env->im);
		env->im = mlx_new_image(env->mlx, 2560, 1315);
		draw(env, env->map);
		mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	}
}

void	zoom_and_size(int keycode, t_struct *env, int value, double scale)
{
	if (keycode == 78 || keycode == 69)
	{
		scale = (value > 200) ? 2 : 5;
		scale = (value > 400) ? 1 : 2;
		env->mz = (keycode == 78) ? env->mz + scale : env->mz - scale;
		mlx_destroy_image(env->mlx, env->im);
		env->im = mlx_new_image(env->mlx, 2560, 1315);
		draw(env, env->map);
		mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	}
	if (keycode == 121 || keycode == 116)
	{
		env->size = (keycode == 121) ? env->size - scale : env->size + scale;
		mlx_destroy_image(env->mlx, env->im);
		env->im = mlx_new_image(env->mlx, 2560, 1315);
		draw(env, env->map);
		mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	}
}

void	resize_and_reset(int keycode, t_struct *env)
{
	if (keycode == 15)
	{
		env->size = 1;
		env->mz = 0;
		env->mx = 0;
		env->my = 0;
		mlx_destroy_image(env->mlx, env->im);
		env->im = mlx_new_image(env->mlx, 2560, 1315);
		draw(env, env->map);
		mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
	}
	else if (keycode == 82 || keycode == 83)
		env->m = (keycode == 82) ? env->m - 1 : env->m + 1;
}

int		hook_main(int keycode, t_struct *env)
{
	double		scale;
	int			value;

	scale = 0.1;
	value = (env->x > env->y) ? env->x : env->y;
	if (value > 200)
		scale = 0.05;
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126)
		directional_move(keycode, env);
	if (keycode == 78 || keycode == 69 || keycode == 121 || keycode == 116)
		zoom_and_size(keycode, env, value, scale);
	if (keycode == 15 || keycode == 82 || keycode == 83)
		resize_and_reset(keycode, env);
	if (keycode == 53)
		exit(0);
	return (1);
}
