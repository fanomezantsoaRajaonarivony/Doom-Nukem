/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:47:53 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:01:18 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	get_map(char **map, t_cube *cube)
{
	int		i;
	t_map	*maps;

	i = 0;
	maps = &cube->map;
	maps->map_line = len_tab(map);
	maps->map = malloc(sizeof(char *) * maps->map_line);
	if (!maps->map)
		return (1);
	while (i <= maps->map_line)
	{
		if (copy_map(map[i], cube, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	get_path(t_text *path, t_cube *cube)
{
	t_path	*paths;

	paths = &cube->path;
	while (path)
	{
		if (id_strstr(path->id, "NO") == 1)
			paths->p_no = path->path;
		else if (id_strstr(path->id, "SO") == 1)
			paths->p_so = path->path;
		else if (id_strstr(path->id, "EA") == 1)
			paths->p_ea = path->path;
		else if (id_strstr(path->id, "WE") == 1)
			paths->p_we = path->path;
		else
			return (1);
		path = path->next;
	}
	return (0);
}

int	get_color(t_color *str, t_cube *cube)
{
	t_path	*path;

	path = &cube->path;
	while (str)
	{
		if (ft_strcmp(str->c_id, "F") == 0)
			path->p_f = ft_atoi(str->red) << 16
				| ft_atoi(str->green) << 8
				| ft_atoi(str->blue);
		else if (ft_strcmp(str->c_id, "C") == 0)
			path->p_c = ft_atoi(str->red) << 16
				| ft_atoi(str->green) << 8
				| ft_atoi(str->blue);
		else
			return (1);
		str = str->next;
	}
	if (path->p_f == -1 || path->p_c == -1)
		return (1);
	return (0);
}

int	get_data(char **tab, t_text *path, t_color *color, t_cube *cube)
{
	if (get_color(color, cube) == 1)
	{
		cube->error = 2;
		return (1);
	}
	if (get_map(tab, cube) == 1)
		return (1);
	if (get_path(path, cube) == 1)
	{
		cube->error = 1;
		return (1);
	}
	return (0);
}

int	get_info(t_cube *cube, char **tab, t_text *path, t_color *color)
{
	cube->window.mlx_ptr = mlx_init();
	if (!cube->window.mlx_ptr)
		return (1);
	if (get_data(tab, path, color, cube) == 1)
		return (1);
	if (get_textur(cube) == 1)
		return (1);
	return (0);
}
