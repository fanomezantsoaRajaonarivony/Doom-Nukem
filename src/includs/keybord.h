/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybord.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:27:07 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:38:51 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBORD_H
# define KEYBORD_H

# include "structur.h"

int	x_exit(t_cube *cube);
int	mouse_move(int x, int y, t_cube *cube);
int	key_press(int keycode, t_cube *get);
int	key_release(int keycode, t_cube *get);

#endif
