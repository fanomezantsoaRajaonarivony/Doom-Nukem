/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 07:58:41 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:07:20 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	init_camera(t_camera *camera, t_player *player)
{
	camera->dirx = 0;
	camera->diry = 0;
	camera->planx = 0;
	camera->plany = 0;
	if (player->start == 'N')
	{
		camera->dirx = -1.0;
		camera->plany = 1.0;
	}
	if (player->start == 'S')
	{
		camera->dirx = 1.0;
		camera->plany = -1.0;
	}
	if (player->start == 'E')
	{
		camera->diry = 1.0;
		camera->planx = 1.0;
	}
	if (player->start == 'W')
	{
		camera->diry = -1.0;
		camera->planx = -1.0;
	}
}

