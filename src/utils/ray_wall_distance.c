/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_wall_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 08:26:16 by frajaona          #+#    #+#             */
/*   Updated: 2025/03/05 08:44:53 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

double	calculate_distance(t_ray *raycast, int is_x)
{
	double	pos_offset;
	double	distance;

	if (is_x)
	{
		pos_offset = (1 - raycast->stepx) * 0.5;
		distance = raycast->mapx - raycast->posx + pos_offset;
	}
	else
	{
		pos_offset = (1 - raycast->stepy) * 0.5;
		distance = raycast->mapy - raycast->posy + pos_offset;
	}
	return (distance);
}

void    compute_wall_dimensions(t_ray *raycast, t_player *player)
{
    int     half_height;
    int     pitch_pixels;
    int     jump_offset;
    int     crouch_off;

    half_height = HEIGHT / 2;
    raycast->lineheight = (int)(HEIGHT / raycast->perpwalldist);

    pitch_pixels = (int)(player->pitch * HEIGHT / 2);
    jump_offset = (int)(player->pos_z / raycast->perpwalldist);
    crouch_off = (int)(player->crouch_offset / raycast->perpwalldist);

    raycast->original_drawstart = half_height - (raycast->lineheight >> 1);
    raycast->drawstart = raycast->original_drawstart - pitch_pixels + jump_offset + crouch_off;
    raycast->drawend   = half_height + (raycast->lineheight >> 1) - pitch_pixels + jump_offset + crouch_off;

    if (raycast->drawstart < 0)
        raycast->drawstart = 0;
    if (raycast->drawend >= HEIGHT)
        raycast->drawend = HEIGHT - 1;
}