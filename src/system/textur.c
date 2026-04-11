/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:37:33 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/17 11:23:48 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"
#include <string.h>

int	load_texture(t_cube *cube, int i, char *path)
{
	cube->texture[i].img = mlx_xpm_file_to_image(cube->window.mlx_ptr, path,
			&(cube->texture[i].width), &(cube->texture[i].height));
	if (!cube->texture[i].img)
		return (1);
	cube->texture[i].addr = (int *)mlx_get_data_addr(cube->texture[i].img,
			&cube->texture[i].bits_per_pixel, &cube->texture[i].line_length,
			&cube->texture[i].endian);
	return (0);
}

void	free_loaded_textures(t_cube *cube, int i)
{
	while (i > 0)
	{
		i--;
		mlx_destroy_image(cube->window.mlx_ptr, cube->texture[i].img);
	}
	cube->error = 3;
}

int	get_textur(t_cube *cube)
{
	int		i;
	char	*path[4];

	i = 0;
	path[0] = cube->path.p_no;
	path[1] = cube->path.p_so;
	path[2] = cube->path.p_we;
	path[3] = cube->path.p_ea;
	while (i < 4)
	{
		if (load_texture(cube, i, path[i]))
		{
			free_loaded_textures(cube, i);
			return (1);
		}
		i++;
	}
	return (0);
}

void	genr_textur(t_cube *get, t_texture *img, t_ray *ray)
{
	init_texture(ray, img);
	img->step = (double)get->texture[img->texdir].height / ray->lineheight;
	img->texx = (int)(img->wallx * (double)get->texture[img->texdir].width);
}
