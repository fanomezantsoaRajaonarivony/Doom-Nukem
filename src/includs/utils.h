/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 09:58:20 by frajaona          #+#    #+#             */
/*   Updated: 2025/05/02 10:16:31 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		len_tab(char **map);
int		convert_color(char *str);
int		get_start(char c, t_player *get, int i, int j);
int		copy_map(char *str, t_cube *get, int i);
int		id_strstr(char *s1, char *s2);

void	get_move_dir(t_cube *get, t_player *player, t_camera *cam,
			double move_dir[2]);
void	get_new_position(t_ray *ray, double move_dir[2], int new_dir[2],
			int map_dir[2]);
void	move_player(t_cube *get, double move_dir[2], int new_dir[2],
			int map_dir[2]);
void	get_side_move(t_cube *get, t_camera *cam, t_player *player,
			double move[2]);
void	apply_side_move(t_cube *get, t_ray *ray, double move[2]);
double	calculate_distance(t_ray *raycast, int is_x);
void	compute_wall_dimensions(t_ray *raycast, t_player *player);
void	calculate_ray_direction(t_ray *raycast, t_camera *cam, int index);
void	calculate_delta_distances(t_ray *raycast);
void	setup_step_x(t_ray *raycast);
void	setup_step_y(t_ray *raycast);
int		char_is_digit(char *s);
#endif
