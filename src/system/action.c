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

void	update_stamina(t_cube *cube)
{
	int	is_running;

	is_running = cube->move.run && (cube->move.forward || cube->move.backward
			|| cube->move.left || cube->move.right)
		&& cube->player.stamina > 0.4 && cube->player.exhaustion_timer == 0;
	if (is_running)
	{
		cube->player.stamina -= 0.4;
		if (cube->player.stamina <= 0)
		{
			cube->player.stamina = 0;
			cube->player.exhausted = 1;
			cube->player.exhaustion_timer = 180; // 3 seconds at 60 FPS
		}
	}
	else if (!is_running) // Regenerate when not running (even if exhausted)
	{
		cube->player.stamina += 0.05;
		if (cube->player.stamina > 100.0)
			cube->player.stamina = 100.0;
	}
	
	// Handle exhaustion timer - only decrease timer, don't clear exhausted state yet
	if (cube->player.exhaustion_timer > 0)
	{
		cube->player.exhaustion_timer--;
		// Only clear exhausted state when timer reaches 0 AND stamina has regenerated to 30
		if (cube->player.exhaustion_timer == 0 && cube->player.stamina >= 30.0)
		{
			cube->player.exhausted = 0;
		}
		else if (cube->player.exhaustion_timer == 0 && cube->player.stamina < 30.0)
		{
			// Keep exhausted state but allow stamina to regenerate to 30
			cube->player.exhausted = 1;
		}
	}
}

void	update_jump(t_cube *cube)
{
	double	gravity;
	double	jump_force;

	gravity = 0.008;
	jump_force = 0.18;

	if (cube->move.jump && !cube->player.is_jumping && cube->player.jump_height <= 0)
	{
		cube->player.is_jumping = 1;
		cube->player.jump_velocity = jump_force;
		cube->move.jump = 0;
	}

	if (cube->player.is_jumping)
	{
		cube->player.jump_height += cube->player.jump_velocity;
		cube->player.jump_velocity -= gravity;
		if (cube->player.jump_height <= 0)
		{
			cube->player.jump_height = 0;
			cube->player.jump_velocity = 0;
			cube->player.is_jumping = 0;
		}
	}
}
