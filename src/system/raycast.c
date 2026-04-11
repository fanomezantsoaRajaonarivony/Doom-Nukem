/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:14:26 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/25 16:05:17 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	get_coordinat(t_ray *raycast, t_camera *cam, int index)
{
	raycast->perpwalldist = 0;
	calculate_ray_direction(raycast, cam, index);
	calculate_delta_distances(raycast);
}

void	setup_ray_direction(t_ray *raycast)
{
	setup_step_x(raycast);
	setup_step_y(raycast);
}

void	perform_dda(t_ray *raycast, t_map *map)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		if (raycast->sidedistx < raycast->sidedisty)
		{
			raycast->sidedistx += raycast->deltadistx;
			raycast->mapx += raycast->stepx;
			raycast->side = 0;
		}
		else
		{
			raycast->sidedisty += raycast->deltadisty;
			raycast->mapy += raycast->stepy;
			raycast->side = 1;
		}
		if (map->map[raycast->mapx][raycast->mapy] == '1')
			i = 1;
	}
}

void	calculate_wall_projection(t_cube *get)
{
	t_ray	*raycast;
	double	inv_raydir;
	double	distance;

	raycast = &get->ray;
	if (raycast->side < EPSILON)
	{
		distance = calculate_distance(raycast, 1);
		inv_raydir = 1.0 / raycast->raydirx;
	}
	else
	{
		distance = calculate_distance(raycast, 0);
		inv_raydir = 1.0 / raycast->raydiry;
	}
	raycast->perpwalldist = distance * inv_raydir;
	compute_wall_dimensions(raycast, &get->player);
}

void	raycasting(t_cube *get)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		get_coordinat(&get->ray, &get->cam, i);
		setup_ray_direction(&get->ray);
		perform_dda(&get->ray, &get->map);
		calculate_wall_projection(get);
		render_wall_column(get, i);
		i++;
	}
}
