/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 08:11:47 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/13 08:38:55 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	rotate_camera(t_move *move, t_camera *cam, t_player *player)
{
	double	val_cos;
	double	val_sin;
	double	old_dirx;
	double	old_planx;
	double	angle;

	angle = 0;
	if (move->rotate_left)
		angle = player->rotet;
	else if (move->rotate_right)
		angle = -player->rotet;
	if (angle == 0)
		return ;
	val_cos = cos(angle);
	val_sin = sin(angle);
	old_dirx = cam->dirx;
	old_planx = cam->planx;
	cam->dirx = cam->dirx * val_cos - cam->diry * val_sin;
	cam->diry = old_dirx * val_sin + cam->diry * val_cos;
	cam->planx = cam->planx * val_cos - cam->plany * val_sin;
	cam->plany = old_planx * val_sin + cam->plany * val_cos;
}

void	move_x(t_cube *get, t_player *player, t_camera *cam, t_ray *ray)
{
	double	move_dir[2];
	int		new_dir[2];
	int		map_dir[2];

	get_move_dir(get, player, cam, move_dir);
	get_new_position(ray, move_dir, new_dir, map_dir);
	move_player(get, move_dir, new_dir, map_dir);
}

void	move_y(t_cube *get, t_player *player, t_camera *cam, t_ray *ray)
{
	double	move[2];

	get_side_move(get, cam, player, move);
	apply_side_move(get, ray, move);
}

void	look_up_down(t_cube *cube)
{
	double	pitch_speed;
	double	max_pitch;

	pitch_speed = 0.02;
	max_pitch = 0.8;
	if (cube->move.look_up)
	{
		cube->player.pitch += pitch_speed;
		if (cube->player.pitch > max_pitch)
			cube->player.pitch = max_pitch;
	}
	else if (cube->move.look_down)
	{
		cube->player.pitch -= pitch_speed;
		if (cube->player.pitch < -max_pitch)
			cube->player.pitch = -max_pitch;
	}
}
