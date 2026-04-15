/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:39:07 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/28 09:41:45 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYSTEM_H
# define SYSTEM_H

# include "structur.h"

int		get_map(char **map, t_cube *cube);
int		get_path(t_text *path, t_cube *cube);
int		get_color(t_color *str, t_cube *cube);
int		get_data(char **tab, t_text *path, t_color *color, t_cube *cube);
int		get_info(t_cube *cube, char **tab, t_text *path, t_color *color);

void	gener_cube(t_cube *cube);

int		get_textur(t_cube *cube);
void	setup_ray_direction(t_ray *raycast);
void	perform_dda(t_ray *raycast, t_map *map);
void	calculate_wall_projection(t_cube *get);
void	genr_textur(t_cube *get, t_texture *img, t_ray *ray);
int		add_color(t_color **color, char *id, char *cl);
int		add_text(t_text **texture, char *id, char *path);

void	get_coordinat(t_ray *raycast, t_camera *cam, int index);
void	raycasting(t_cube *get);

int		render_wall_column(t_cube *get, int index);

void	rotate_camera(t_move *move, t_camera *cam, t_player *player);
void	move_x(t_cube *get, t_player *player, t_camera *cam, t_ray *ray);
void	move_y(t_cube *get, t_player *player, t_camera *cam, t_ray *ray);
void	look_up_down(t_cube *cube);
void	update_stamina(t_cube *cube);
void	display_stamina(t_cube *cube);
void	update_jump(t_cube *cube);

#endif