/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:32:03 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/12 14:32:54 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

t_file	*init_file(void)
{
	t_file	*res;

	res = malloc(sizeof(t_file));
	if (!res)
		return (NULL);
	res->entry = NULL;
	res->input = NULL;
	res->next = NULL;
	res->col_i = 0;
	res->text_i = 0;
	return (res);
}

void	init_par(t_par *res)
{
	res->height = 0;
	res->map_line = 0;
	res->width = 0;
}

t_text	*init_text(void)
{
	t_text	*in;

	in = malloc(sizeof(t_text));
	in->id = NULL;
	in->path = NULL;
	in->next = NULL;
	return (in);
}

t_color	*init_color(void)
{
	t_color	*col;

	col = malloc(sizeof(t_color));
	col->c_id = NULL;
	col->color = NULL;
	col->next = NULL;
	col->red = NULL;
	col->green = NULL;
	col->blue = NULL;
	col->color_sep = NULL;
	return (col);
}

void	copy_file(t_file *file, char *line)
{
	file->entry = ft_strdup(line);
	file->next = init_file();
	file->input = ft_split(file->entry, ' ');
}
