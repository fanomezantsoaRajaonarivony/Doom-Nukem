/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:12:49 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/19 10:15:24 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	map_part(t_file *file, t_par *map, t_color **color)
{
	if (check_map(file, map) == -1)
	{
		if (map)
			free_par(map);
		if (*color)
			free_color(*color);
		return (-1);
	}
	return (0);
}

int	check_is_correct(t_file *file)
{
	if (ft_strcmp(file->input[0], "NO") == 0 || ft_strcmp(file->input[0],
			"SO") == 0 || ft_strcmp(file->input[0], "EA") == 0
		|| ft_strcmp(file->input[0], "WE") == 0 || ft_strncmp(file->input[0],
			"F", 1) == 0 || ft_strncmp(file->input[0], "C", 1) == 0)
		return (0);
	return (1);
}
