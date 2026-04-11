/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:46:54 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/28 09:43:22 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	start_cube(t_cube *cube)
{
	raycasting(cube);
	mlx_put_image_to_window(cube->window.mlx_ptr, cube->window.mlx_win,
		cube->data.img, 0, 0);
	move_x(cube, &cube->player, &cube->cam, &cube->ray);
	move_y(cube, &cube->player, &cube->cam, &cube->ray);
	rotate_camera(&cube->move, &cube->cam, &cube->player);
	look_up_down(cube);
	return (0);
}

void	gener_cube(t_cube *cube)
{
	cube->window.mlx_win = mlx_new_window(cube->window.mlx_ptr, WIDTH, HEIGHT,
			"Cat_Sans_Cat");
	mlx_mouse_hide(cube->window.mlx_ptr, cube->window.mlx_win);
	cube->data.img = mlx_new_image(cube->window.mlx_ptr, WIDTH, HEIGHT);
	cube->data.addr = (int *)mlx_get_data_addr(cube->data.img,
			&cube->data.bits_per_pixel, &cube->data.line_length,
			&cube->data.endian);
	cube->data.width = WIDTH;
	cube->data.height = HEIGHT;
	cube->ray.posx = cube->player.dx + 0.5;
	cube->ray.posy = cube->player.dy + 0.5;
	start_cube(cube);
	mlx_hook(cube->window.mlx_win, 33, 1L << 17, x_exit, cube);
	mlx_hook(cube->window.mlx_win, 2, 1L << 0, key_press, cube);
	mlx_hook(cube->window.mlx_win, 3, 1L << 1, key_release, cube);
	mlx_hook(cube->window.mlx_win, 6, 1L<<6, mouse_move, cube);
	mlx_loop_hook(cube->window.mlx_ptr, start_cube, cube);
	mlx_loop(cube->window.mlx_ptr);
}
