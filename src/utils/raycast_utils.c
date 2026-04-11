/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:21:27 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/13 09:42:56 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	calculate_ray_direction(t_ray *raycast, t_camera *cam, int index)
{
	cam->camerax = 2 * index / (double)WIDTH - 1;
	raycast->raydirx = cam->dirx + cam->planx * cam->camerax;
	raycast->raydiry = cam->diry + cam->plany * cam->camerax;
	raycast->mapx = (int)raycast->posx;
	raycast->mapy = (int)raycast->posy;
}

void	calculate_delta_distances(t_ray *raycast)
{
	if (fabs(raycast->raydiry) < EPSILON)
		raycast->deltadistx = 0;
	else if (fabs(raycast->raydirx) < EPSILON)
		raycast->deltadistx = 1;
	else
		raycast->deltadistx = 1 / fabs(raycast->raydirx);
	if (fabs(raycast->raydirx) < EPSILON)
		raycast->deltadisty = 0;
	else if (fabs(raycast->raydiry) < EPSILON)
		raycast->deltadisty = 1;
	else
		raycast->deltadisty = 1 / fabs(raycast->raydiry);
}

void	setup_step_x(t_ray *raycast)
{
	if (raycast->raydirx <= EPSILON)
	{
		raycast->stepx = -1;
		raycast->sidedistx = (raycast->posx - raycast->mapx)
			* raycast->deltadistx;
	}
	else
	{
		raycast->stepx = 1;
		raycast->sidedistx = (raycast->mapx + 1.0 - raycast->posx)
			* raycast->deltadistx;
	}
}

void	setup_step_y(t_ray *raycast)
{
	if (raycast->raydiry <= EPSILON)
	{
		raycast->stepy = -1;
		raycast->sidedisty = (raycast->posy - raycast->mapy)
			* raycast->deltadisty;
	}
	else
	{
		raycast->stepy = 1;
		raycast->sidedisty = (raycast->mapy + 1.0 - raycast->posy)
			* raycast->deltadisty;
	}
}
