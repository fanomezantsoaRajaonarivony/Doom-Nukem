/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:15:22 by frajaona          #+#    #+#             */
/*   Updated: 2025/05/02 09:28:06 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includs/cub.h"

int	check_it(t_text *texture)
{
	if (check_xpm(texture) == -1)
		return (-1);
	if (!texture)
	{
		ft_putstr_fd("Error\nMissing texture elements\n", 2);
		return (-1);
	}
	if (open_texture(texture->path) == -1)
		return (-1);
	return (0);
}

int	check_back(t_file *file)
{
	while (file)
	{
		if (file->entry && ft_strcmp(file->entry, "\0") == 0
			&& file->next->entry && ft_strcmp(file->next->entry, "\0") != 0)
		{
			ft_putstr_fd("Error\nNo elements after map\n", 2);
			return (-1);
		}
		file = file->next;
	}
	return (0);
}

void	free_main(t_cube cube)
{
	if (cube.error == 98)
	{
		if (cube.text)
			free_text(cube.text);
		if (cube.col)
			free_color(cube.col);
		if (cube.file)
			free_file(cube.file);
		if (&cube.maps)
			free_par(&cube.maps);
	}
	if (cube.error == 99)
	{
		if (cube.text)
			free_text(cube.text);
		if (cube.file)
			free_file(cube.file);
	}
}

int	main(int argc, char **argv)
{
	t_cube	cube;
	int		fd;
	int		i;

	i = 0;
	if (args_error(argc, argv) == -1)
	{
		return (1);
	}
	fd = open_file(&argv[1][i]);
	basic_init(&cube);
	if (create_cube(fd, &cube) == -1)
		return (1);
	init_par(&cube.maps);
	if (mix_check(&cube) == -1)
		return (1);
	init_cube(&cube);
	if (cube_extent(&cube, cube.maps, cube.text, cube.col) == 0)
		return (0);
	return (0);
}
