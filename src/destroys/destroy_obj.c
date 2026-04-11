/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:51:56 by frajaona          #+#    #+#             */
/*   Updated: 2025/03/12 14:46:15 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (i < map->map_line)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	free_mlx(t_window *mlx)
{
	if (mlx->mlx_win)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		mlx->mlx_win = NULL;
	}
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
}

void	destroy(t_cube *cube)
{
	if (cube->window.mlx_ptr)
	{
		mlx_destroy_display(cube->window.mlx_ptr);
		free(cube->window.mlx_ptr);
	}
}

void	free_textures(t_window *mlx, t_data textur[4])
{
	int	i;

	i = 0;
	if (!mlx || !mlx->mlx_ptr)
		return ;
	while (i < 4)
	{
		if (textur[i].img)
		{
			mlx_destroy_image(mlx->mlx_ptr, textur[i].img);
			textur[i].img = NULL;
		}
		i++;
	}
	free_mlx(mlx);
}
