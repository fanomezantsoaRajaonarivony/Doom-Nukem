/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:05:35 by tokrandr          #+#    #+#             */
/*   Updated: 2025/05/02 09:37:42 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	add_color(t_color **color, char *id, char *cl)
{
	t_color	*col;

	col = malloc(sizeof(t_color));
	if (!col)
		return (-1);
	col->c_id = id;
	col->color = cl;
	col->red = NULL;
	col->green = NULL;
	col->blue = NULL;
	col->next = *color;
	*color = col;
	return (0);
}

int	add_text(t_text **texture, char *id, char *path)
{
	t_text	*in;

	in = malloc(sizeof(t_text));
	if (!in)
		return (-1);
	in->id = id;
	in->path = path;
	in->next = *texture;
	*texture = in;
	return (0);
}

int	manage_file(t_file *file, t_text **texture, t_color **color)
{
	if (file->input[2])
	{
		ft_putstr_fd("Error\nWrong map data\n", 2);
		return (-1);
	}
	if (ft_strcmp(file->input[0], "NO") == 0 || ft_strcmp(file->input[0],
			"SO") == 0 || ft_strcmp(file->input[0], "EA") == 0
		|| ft_strcmp(file->input[0], "WE") == 0)
		add_text(texture, ft_strdup(file->input[0]), ft_strdup(file->input[1]));
	if (ft_strcmp(file->input[0], "F") == 0 || ft_strcmp(file->input[0],
			"C") == 0)
	{
		add_color(color, ft_strdup(file->input[0]), ft_strdup(file->input[1]));
		if (parse_color_numbers(*color) == -1)
			return (-1);
		if (check_color_values(*color) == -1)
			return (-1);
	}
	return (0);
}

int	two_dim_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
