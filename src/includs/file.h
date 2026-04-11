/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:25:24 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:20:04 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "structur.h"

int		*get_player_pos(t_par *map);
int		check_spaces(t_par *map);
int		check_void(t_par *map);
int		check_valid_zero(char *valid, char c);
int		check_line(t_par *map);

int		open_file(char *file);
int		map_chars(t_par *map);
int		map_chars_counter(t_par *map);
int		check_map(t_file *file, t_par *map);
int		map_line(t_file *file);
int		check_id(t_file *file, t_text **texture, t_color **color, t_par *map);
int		parse_color_numbers(t_color *color);
void	print_color_values(t_color *color, char target);
int		check_color_values(t_color *color);

t_file	*init_file(void);

void	init_par(t_par *res);
t_file	*parse_file(int fd);
t_text	*init_text(void);
t_color	*init_color(void);

void	free_input(char **str);
void	free_me(t_file *file);
void	line_space(t_file **file);

#endif