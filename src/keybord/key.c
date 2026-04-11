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