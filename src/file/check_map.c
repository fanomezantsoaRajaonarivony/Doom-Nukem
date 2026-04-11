/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:23:43 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/19 10:06:29 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	second_loop_spaces(t_par *map, size_t values[2], size_t i, int j)
{
	if (map->map[j][i] == '0' || map->map[j][i] == 'N' || map->map[j][i] == 'S'
	|| map->map[j][i] == 'E' || map->map[j][i] == 'W')
	{
		if (i > values[0] || i > values[1])
		{
			ft_putstr_fd("Error\nMap is not closed\n", 2);
			return (-1);
		}
		if (map->map[j - 1][i] == ' ' || map->map[j + 1][i] == ' '
			|| map->map[j][i - 1] == ' ' || map->map[j][i + 1] == ' ')
		{
			ft_putstr_fd("Error\nMap is not closed\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	check_spaces(t_par *map)
{
	size_t	i;
	size_t	col;
	int		j;
	size_t	values[2];

	j = -1;
	while (++j < map->map_line)
	{
		col = ft_strlen(map->map[j]);
		i = -1;
		if (j > 0)
			values[0] = ft_strlen(map->map[j - 1]);
		if (j < map->map_line - 1)
			values[1] = ft_strlen(map->map[j + 1]);
		i = -1;
		while (++i < col)
		{
			if (second_loop_spaces(map, values, i, j) == -1)
				return (-1);
		}
	}
	return (0);
}

int	second_loop_void(t_par *map, size_t values[2], size_t i, int j)
{
	if (map->map[j][i] == '0' || map->map[j][i] == 'N' || map->map[j][i] == 'S'
		|| map->map[j][i] == 'E' || map->map[j][i] == 'W')
	{
		if (i > values[0] || i > values[1])
		{
			ft_putstr_fd("Error\nMap is not closed\n", 2);
			return (-1);
		}
		if (map->map[j - 1][i] == '\0' || map->map[j + 1][i] == '\0'
			|| map->map[j][i - 1] == '\0' || map->map[j][i + 1] == '\0')
		{
			ft_putstr_fd("Error\nMap is not closed\n", 2);
			return (-1);
		}
	}
	return (0);
}

int	check_void(t_par *map)
{
	size_t	i;
	size_t	col;
	int		j;
	size_t	values[2];

	j = -1;
	while (++j < map->map_line)
	{
		col = ft_strlen(map->map[j]);
		if (j > 0)
			values[0] = ft_strlen(map->map[j - 1]);
		if (j < map->map_line - 1)
			values[1] = ft_strlen(map->map[j + 1]);
		i = -1;
		while (++i < col)
		{
			if (second_loop_void(map, values, i, j) == -1)
				return (-1);
		}
	}
	return (0);
}

int	check_valid_zero(char *valid, char c)
{
	while (*valid)
	{
		if (*valid == c)
			return (1);
		valid++;
	}
	return (0);
}
