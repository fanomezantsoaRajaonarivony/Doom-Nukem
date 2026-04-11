/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:46:42 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:04:38 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	get_move_dir(t_cube *get, t_player *player, t_camera *cam,
		double move_dir[2])
{
	double	move_step;

	move_step = player->move * 0.2;
	move_dir[0] = 0;
	move_dir[1] = 0;
	if (get->move.forward)
	{
		move_dir[0] = cam->dirx * move_step;
		move_dir[1] = cam->diry * move_step;
	}
	else if (get->move.backward)
	{
		move_dir[0] = -cam->dirx * move_step;
		move_dir[1] = -cam->diry * move_step;
	}
}

void	get_new_position(t_ray *ray, double move_dir[2], int new_dir[2],
		int map_dir[2])
{
	new_dir[0] = (int)(ray->posx + move_dir[0]);
	new_dir[1] = (int)(ray->posy + move_dir[1]);
	map_dir[0] = (int)ray->posx;
	map_dir[1] = (int)ray->posy;
}

void	move_player(t_cube *get, double move_dir[2], int new_dir[2],
		int map_dir[2])
{
	int	map_val_dir[2];

	map_val_dir[0] = get->map.map[new_dir[0]][map_dir[1]];
	map_val_dir[1] = get->map.map[map_dir[0]][new_dir[1]];
	if (map_val_dir[0] == '0')
		get->ray.posx += move_dir[0] / 2;
	if (map_val_dir[1] == '0')
		get->ray.posy += move_dir[1] / 2;
}

void	get_side_move(t_cube *get, t_camera *cam, t_player *player,
		double move[2])
{
	double	move_step;

	move_step = player->move * 0.2;
	move[0] = 0;
	move[1] = 0;
	if (get->move.right == 1)
	{
		move[0] = cam->diry * move_step;
		move[1] = -cam->dirx * move_step;
	}
	else if (get->move.left == 1)
	{
		move[0] = -cam->diry * move_step;
		move[1] = cam->dirx * move_step;
	}
}

void	apply_side_move(t_cube *get, t_ray *ray, double move[2])
{
	if (move[0] != 0 && get->map.map[(int)(ray->posx
			+ move[0])][(int)ray->posy] == '0')
		ray->posx += move[0] / 2;
	if (move[1] != 0 && get->map.map[(int)ray->posx][(int)(ray->posy
		+ move[1])] == '0')
		ray->posy += move[1] / 2;
}
