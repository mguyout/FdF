/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:48:33 by mguyout           #+#    #+#             */
/*   Updated: 2017/04/07 20:40:17 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**create_line(int **map, t_struct *env, char *line)
{
	int		i;
	int		x;
	char	**tab;

	tab = ft_strsplit(line, ' ');
	x = 0;
	i = -1;
	while (line[++i])
		if (line[i] != ' ' && i < ft_strlen(line))
		{
			x++;
			while (line[i] && line[i] != ' ')
				i++;
		}
	if (x < 2)
		return (0);
	map[env->y] = (int*)malloc(sizeof(int) * (x));
	x = -1;
	while (++x < env->x)
	{
		map[env->y][x] = ft_atoi(tab[x]);
		free(tab[x]);
	}
	return (map);
}

int	check_map_core(int i, char *line)
{
	int length;

	length = 0;
	while (line[++i])
	{
		if ((line[i] < '0' || line[i] > '9') &&
line[i] != ' ' && line[i] != '-')
			return (0);
		if (line[i] >= '0' && line[i] <= '9')
		{
			length++;
			while (line[i + 1] && line[i] >= '0' && line[i] <= '9')
				i++;
			if (line[i + 1] && line[i] != ' ')
				return (0);
		}
	}
	return (length);
}

int	check_map(int fd, t_struct *env)
{
	char	*line;
	int		i;
	int		length;
	int		height;

	height = 0;
	length = 0;
	env->x = 0;
	while ((env->ret = get_next_line(fd, &line)) != 0)
	{
		if (env->ret == -1)
			return (0);
		i = -1;
		if ((length = check_map_core(i, line)) == 0)
			return (0);
		if (env->x > 0 && env->x != length)
			return (0);
		env->x = length;
		height++;
	}
	return (height);
}

int	**create_map(int fd, char **argv, t_struct *env)
{
	int		**map;
	char	*line;

	if ((env->y = check_map(fd, env)) == 0)
		return (0);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (!(map = (int**)malloc(sizeof(int*) * (env->y + 2))))
		return (0);
	map[env->y] = NULL;
	env->y = 0;
	while ((env->ret = get_next_line(fd, &line)) != 0)
	{
		if (env->ret == -1)
			return (0);
		if (!(map = create_line(map, env, line)))
			return (0);
		env->y++;
	}
	close(fd);
	return (map);
}
