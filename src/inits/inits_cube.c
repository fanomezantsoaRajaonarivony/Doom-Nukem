/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_cube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:08:31 by frajaona          #+#    #+#             */
/*   Updated: 2025/05/02 09:36:17 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	init_player(t_player *player)
{
	player->dx = 0;
	player->dy = 0;
	player->pos_x = 0;
	player->pos_y = 0;
	player->move = 0.1;
	player->rotet = 0.01;
	player->pitch = 0.0;
}

void	init_map(t_map *map)
{
	map->map_line = 0;
	map->map = NULL;
}

void	init_path(t_path *path)
{
	path->p_no = NULL;
	path->p_ea = NULL;
	path->p_so = NULL;
	path->p_we = NULL;
	path->p_f = -1;
	path->p_c = -1;
}

void	init_move(t_move *move)
{
	move->forward = 0;
	move->backward = 0;
	move->left = 0;
	move->right = 0;
	move->rotate_left = 0;
	move->rotate_right = 0;
	move->look_up = 0;
	move->look_down = 0;
}

void	init_cube(t_cube *data)
{
	data->error = 0;
	init_player(&data->player);
	init_map(&data->map);
	init_path(&data->path);
	init_move(&data->move);
}

void	init_texture(t_ray *raycast, t_texture *textur)
{
	if (raycast->side == 0 && raycast->raydirx < EPSILON)
		textur->texdir = 1;
	if (raycast->side == 0 && raycast->raydirx >= EPSILON)
		textur->texdir = 0;
	if (raycast->side == 1 && raycast->raydiry < EPSILON)
		textur->texdir = 3;
	if (raycast->side == 1 && raycast->raydiry >= EPSILON)
		textur->texdir = 2;
	if (raycast->side == 0)
		textur->wallx = raycast->posy + raycast->perpwalldist
			* raycast->raydiry;
	else
		textur->wallx = raycast->posx + raycast->perpwalldist
			* raycast->raydirx;
	textur->wallx -= floor((textur->wallx));
}
