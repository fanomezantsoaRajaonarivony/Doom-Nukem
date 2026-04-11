/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:31:50 by tokrandr          #+#    #+#             */
/*   Updated: 2025/05/02 10:15:26 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	check_map(t_file *file, t_par *map)
{
	int	i;
	int	line;

	line = map_line(file);
	map->map_line = line;
	map->map = (char **)malloc(sizeof(char *) * (line + 1));
	if (!map->map)
		return (-1);
	i = 0;
	while (file)
	{
		if (file->next == NULL)
			break ;
		map->map[i] = file->entry;
		if (!map->map[i])
			return (-1);
		file = file->next;
		i++;
	}
	map->map[i] = NULL;
	if (check_all(map) == -1)
		return (-1);
	return (0);
}

int	map_line(t_file *file)
{
	int	y;

	y = 0;
	while (file)
	{
		if (file->entry && file->entry[0] != '\0')
			y++;
		file = file->next;
	}
	return (y);
}

int	check_id(t_file *file, t_text **texture, t_color **color, t_par *map)
{
	int	len;

	len = -1;
	if (file_error(file) == -1)
		return (-1);
	while (++len < 6 && check_is_correct(file) == 0)
	{
		if (file->input)
		{
			if (manage_file(file, texture, color) == -1)
			{
				free_color(*color);
				return (-1);
			}
		}
		file = file->next;
	}
	if (map_part(file, map, color) == -1)
		return (-1);
	return (0);
}

int	parse_color_numbers(t_color *color)
{
	if (color->color)
		color->color_sep = ft_split(color->color, ',');
	if (color->color_sep[0] == NULL || color->color_sep[1] == NULL
		|| color->color_sep[2] == NULL)
	{
		ft_putstr_fd("Error\nMissing color value\n", 2);
		return (-1);
	}
	color->red = color->color_sep[0];
	color->green = color->color_sep[1];
	color->blue = color->color_sep[2];
	return (1);
}

int	check_color_values(t_color *color)
{
	if (char_is_digit(color->red) == -1 || (char_is_digit(color->green) == -1)
		|| char_is_digit(color->blue) == -1)
	{
		ft_putstr_fd("Error\nUse only digit in color values\n", 2);
		return (-1);
	}
	if ((ft_atoi(color->red) < 0 || ft_atoi(color->red) > 255)
		|| (ft_atoi(color->green) < 0 || ft_atoi(color->green) > 255)
		|| (ft_atoi(color->blue) < 0 || ft_atoi(color->blue) > 255))
	{
		ft_putstr_fd("Error\nColor values must be between 0 to 255\n", 2);
		return (-1);
	}
	if (two_dim_len(color->color_sep) != 3)
	{
		ft_putstr_fd("Error\n3 values needed\n", 2);
		return (-1);
	}
	return (0);
}
