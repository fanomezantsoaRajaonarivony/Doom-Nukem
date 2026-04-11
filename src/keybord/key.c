/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:37:37 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/13 08:37:53 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	mouse_move(int x, int y, t_cube *cube)
{
	int			center_x;
	int			center_y;
	int			dx;
	int			dy;
	double		angle;
	double		val_cos;
	double		val_sin;
	double		old_dirx;
	double		old_planx;

	if (!cube->move.mouse_mode)
		return (0);
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	if (x == center_x && y == center_y)
		return (0);
	dx = x - center_x;
	dy = y - center_y;
	if (dx != 0)
	{
		angle = -dx * 0.003;
		val_cos = cos(angle);
		val_sin = sin(angle);
		old_dirx = cube->cam.dirx;
		old_planx = cube->cam.planx;
		cube->cam.dirx = cube->cam.dirx * val_cos - cube->cam.diry * val_sin;
		cube->cam.diry = old_dirx * val_sin + cube->cam.diry * val_cos;
		cube->cam.planx = cube->cam.planx * val_cos - cube->cam.plany * val_sin;
		cube->cam.plany = old_planx * val_sin + cube->cam.plany * val_cos;
	}
	if (dy != 0)
	{
		cube->player.pitch += dy * 0.003;
		if (cube->player.pitch > 0.8)
			cube->player.pitch = 0.8;
		else if (cube->player.pitch < -0.8)
			cube->player.pitch = -0.8;
	}
	mlx_mouse_move(cube->window.mlx_ptr, cube->window.mlx_win, center_x, center_y);
	return (0);
}

int	x_exit(t_cube *cube)
{
	free_cube(cube);
	exit(0);
}
int key_press(int keycode, t_cube *get)
{
    if (keycode == 119)
        get->move.forward = 1;
    else if (keycode == 115)
        get->move.backward = 1;
    else if (keycode == 97)
        get->move.left = 1;
    else if (keycode == 100)
        get->move.right = 1;
    else if (keycode == 65361)
        get->move.rotate_left = 1;
    else if (keycode == 65363)
        get->move.rotate_right = 1;
    else if (keycode == 65362)
        get->move.look_down = 1;  // était look_up
    else if (keycode == 65364)
        get->move.look_up = 1;    // était look_down
    else if (keycode == 65481)
    {
        get->move.mouse_mode ^= 1;  // F12 toggle mouse mode
        if (get->move.mouse_mode)
            mlx_mouse_hide(get->window.mlx_ptr, get->window.mlx_win);
        else
            mlx_mouse_show(get->window.mlx_ptr, get->window.mlx_win);
    }
    else if (keycode == 65307)
        x_exit(get);
    return (1);
}

int key_release(int keycode, t_cube *get)
{
    if (keycode == 119)
        get->move.forward = 0;
    else if (keycode == 115)
        get->move.backward = 0;
    else if (keycode == 97)
        get->move.left = 0;
    else if (keycode == 100)
        get->move.right = 0;
    else if (keycode == 65361)
        get->move.rotate_left = 0;
    else if (keycode == 65363)
        get->move.rotate_right = 0;
    else if (keycode == 65362)
        get->move.look_down = 0;  // était look_up
    else if (keycode == 65364)
        get->move.look_up = 0;    // était look_down
    return (1);
}