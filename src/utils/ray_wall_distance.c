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

    half_height = HEIGHT / 2;
    // CORRECTION : cast en int pour éviter l'étirement
    raycast->lineheight = (int)(HEIGHT / raycast->perpwalldist);
    pitch_pixels = (int)(player->pitch * HEIGHT / 2);

    raycast->original_drawstart = half_height - (raycast->lineheight >> 1);
    raycast->drawstart = raycast->original_drawstart - pitch_pixels;
    raycast->drawend   = half_height + (raycast->lineheight >> 1) - pitch_pixels;

    if (raycast->drawstart < 0)
        raycast->drawstart = 0;
    if (raycast->drawend >= HEIGHT)
        raycast->drawend = HEIGHT - 1;
}