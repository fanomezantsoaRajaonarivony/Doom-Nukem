/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:22:59 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:38:43 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structur.h"

void	init_camera(t_camera *camera, t_player *player);
void	init_move(t_move *moves);

void	init_cube(t_cube *cube);
void	init_texture(t_ray *raycast, t_texture *textur);

#endif