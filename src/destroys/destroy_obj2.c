/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_obj2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:47:46 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/19 09:55:57 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	free_cube(t_cube *cube)
{
	free_text(cube->text);
	free_color(cube->col);
	free_file(cube->file);
	free_par(&cube->maps);
	if (&cube->map != NULL)
		free_map(&cube->map);
	if (cube->error == 1 || cube->error == 2 || cube->error == 3)
	{
		if (cube->error == 1)
			ft_putstr_fd("Error\nMissing texture path\n", 2);
		if (cube->error == 2)
			ft_putstr_fd("Error\nMissing color elements\n", 2);
		if (cube->error == 3)
			ft_putstr_fd("Error\nMissing texture elements\n", 2);
		destroy(cube);
		return ;
	}
	if (&cube->window.mlx_ptr != NULL)
	{
		mlx_destroy_image(cube->window.mlx_ptr, cube->data.img);
		free_textures(&cube->window, cube->texture);
	}
}

void	free_all(t_text *text, t_color *color, t_par *par, t_file *file)
{
	if (text)
		free_text(text);
	if (color)
		free_color(color);
	free_par(par);
	if (file)
		free_file(file);
}

void	free_file(t_file *file)
{
	t_file	*tmp;

	while (file)
	{
		tmp = file->next;
		free(file->entry);
		if (file->input)
			free_tabs(file->input);
		free(file);
		file = tmp;
	}
}
