/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:37:33 by frajaona          #+#    #+#             */
/*   Updated: 2025/03/12 14:46:20 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	free_tab(char **tab)
{
	if (tab != NULL)
		free(tab);
}

void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i] != NULL)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_text(t_text *text)
{
	t_text	*tmp;

	while (text)
	{
		tmp = text->next;
		free(text->id);
		free(text->path);
		free(text);
		text = tmp;
	}
}

void	free_color(t_color *color)
{
	t_color	*tmp;

	while (color)
	{
		tmp = color->next;
		free(color->c_id);
		free(color->color);
		free_tabs(color->color_sep);
		free(color);
		color = tmp;
	}
}

void	free_par(t_par *par)
{
	if (!par)
		return ;
	if (par->map)
		free_tab(par->map);
}
