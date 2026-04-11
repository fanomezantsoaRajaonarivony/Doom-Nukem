/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:59:16 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/19 10:11:56 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	map_chars_counter(t_par *map)
{
	size_t	i;
	int		j;
	int		k;
	size_t	col;
	int		start_count;

	start_count = 0;
	j = -1;
	while (++j < map->map_line)
	{
		col = ft_strlen(map->map[j]);
		i = -1;
		while (++i < col)
		{
			k = -1;
			while (VALID[++k])
			{
				if (VALID[k] == map->map[j][i])
					start_count++;
			}
		}
	}
	return (start_count);
}

int	compile_check(char *line, int *count)
{
	size_t	i;
	size_t	col;

	col = ft_strlen(line);
	i = -1;
	while (++i < col)
	{
		if (check_valid(line[i]) == 0)
		{
			ft_putstr_fd("Error\nInvalid char in map\n", 2);
			return (-1);
		}
		if (check_player(line[i]) == 1)
			(*count)++;
	}
	return (0);
}

int	map_chars(t_par *map)
{
	int	j;
	int	count;

	j = -1;
	count = 0;
	while (++j < map->map_line)
	{
		if (compile_check(map->map[j], &count) == -1)
			return (-1);
	}
	if (count != 1)
	{
		ft_putstr_fd("Error\nOne of NSEW required\n", 2);
		return (-1);
	}
	return (0);
}

int	check_all(t_par *map)
{
	if (map->map[0] == NULL)
	{
		ft_putstr_fd("Error\nMissing Maps elements\n", 2);
		return (-1);
	}
	if (check_line(map) == -1)
	{
		ft_putstr_fd("Error\nMap is not closed line\n", 2);
		return (-1);
	}
	if (map_chars_counter(map) > 1)
	{
		ft_putstr_fd("Error\nToo many players\n", 2);
		return (-1);
	}
	if (map_chars(map) == -1 || check_spaces(map) == -1
		|| check_void(map) == -1)
		return (-1);
	return (0);
}

int	check_line(t_par *map)
{
	int		j;
	char	*value;

	j = -1;
	value = "NSEW";
	if (check_valid_zero(map->map[0], '0') == 1)
		return (-1);
	if (check_valid_zero(map->map[map->map_line - 1], '0') == 1)
		return (-1);
	while (*value)
	{
		if (check_valid_zero(map->map[0], *value) == 1)
			return (-1);
		if (check_valid_zero(map->map[map->map_line - 1], *value) == 1)
			return (-1);
		value++;
	}
	while (++j < map->map_line)
	{
		if (check_valid_zero_col(map->map[j][0], '0') == 1)
			return (-1);
		if (check_valid_zero("NSEW", map->map[j][0]) == 1)
			return (-1);
	}
	return (0);
}
