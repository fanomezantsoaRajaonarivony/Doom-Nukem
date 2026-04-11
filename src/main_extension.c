/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:36:59 by tokrandr          #+#    #+#             */
/*   Updated: 2025/04/28 09:41:35 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	cube_extent(t_cube *cube, t_par maps, t_text *texture, t_color *col)
{
	if (get_info(cube, maps.map, texture, col) == 1)
	{
		free_cube(cube);
		return (1);
	}
	init_camera(&cube->cam, &cube->player);
	gener_cube(cube);
	free_cube(cube);
	return (0);
}

int	args_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc <= 1)
	{
		ft_putstr_fd("Error\nToo few arguments\n", 2);
		return (-1);
	}
	if (check_error(&argv[1][i]) == -1)
		return (-1);
	return (0);
}

void	basic_init(t_cube *cube)
{
	cube->file = NULL;
	cube->col = NULL;
	cube->text = NULL;
}

int	create_cube(int fd, t_cube *cube)
{
	cube->file = parse_file(fd);
	if (cube->file != NULL && check_back(cube->file) == -1)
	{
		free_file(cube->file);
		return (-1);
	}
	line_space(&cube->file);
	if (!cube->file)
		return (-1);
	return (0);
}

int	mix_check(t_cube *cube)
{
	if (check_id(cube->file, &cube->text, &cube->col, &cube->maps) == -1)
	{
		cube->error = 99;
		free_main(*cube);
		return (-1);
	}
	if (check_it(cube->text) == -1)
	{
		cube->error = 98;
		free_main(*cube);
		return (-1);
	}
	return (0);
}
