/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:53:31 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:22:19 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H

# include "structur.h"

void	free_tab(char **tab);
void	free_file(t_file *file);
void	free_color(t_color *color);
void	free_text(t_text *text);
void	free_par(t_par *par);
void	free_textures(t_window *mlx, t_data textur[4]);
void	free_map(t_map *map);
void	free_all(t_text *text, t_color *color, t_par *par, t_file *file);
void	destroy(t_cube *cube);
void	free_main(t_cube cube);

void	free_cube(t_cube *cube);
void	free_tabs(char **tab);

#endif
