/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:28:47 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/12 14:29:13 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	check_xpm(t_text *texture)
{
	while (texture)
	{
		if (check_extension_error(texture->path) == -1)
			return (-1);
		texture = texture->next;
	}
	return (0);
}

int	file_error(t_file *file)
{
	if (!file->input)
	{
		ft_putstr_fd("Error\nEmpty file\n", 2);
		return (-1);
	}
	return (0);
}
