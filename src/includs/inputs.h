/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:26:37 by frajaona          #+#    #+#             */
/*   Updated: 2025/05/03 13:25:49 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

int		analyze_extension(char *str);
int		check_args(char *av);
int		check_error(char *path);
int		check_player(char c);
int		check_extension_error(char *s);
int		open_texture(char *file);
int		check_valid(char c);
int		check_all(t_par *map);
int		manage_file(t_file *file, t_text **texture, t_color **color);
int		check_xpm(t_text *texture);
int		search_for_tab(char *s);
int		two_dim_len(char **tab);
int		check_valid_zero_col(char valid, char c);
int		mix_check(t_cube *cube);
int		args_error(int argc, char **argv);
void	basic_init(t_cube *cube);
int		create_cube(int fd, t_cube *cube);
int		check_xpm(t_text *texture);
int		check_it(t_text *texture);
int		check_back(t_file *file);
void	copy_file(t_file *file, char *line);
int		cube_extent(t_cube *cube, t_par maps, t_text *texture, t_color *col);
int		file_error(t_file *file);
int		map_part(t_file *file, t_par *map, t_color **color);
int		check_is_correct(t_file *file);

#endif
