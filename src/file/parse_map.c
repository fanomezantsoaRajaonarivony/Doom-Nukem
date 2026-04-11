/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:58:16 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/19 09:57:46 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	free_input(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_me(t_file *file)
{
	t_file	*cur;

	cur = NULL;
	while (cur)
	{
		cur = file;
		free(cur->entry);
		free_input(cur->input);
		free(cur);
		file = file->next;
	}
}

void	line_space(t_file **file)
{
	t_file	*prev;
	t_file	*cur;

	prev = NULL;
	cur = *file;
	while (cur)
	{
		if (!cur->entry)
			break ;
		if (cur->entry[0] == '\0')
		{
			if (prev)
				prev->next = cur->next;
			free(cur->entry);
			free_input(cur->input);
			free(cur);
			cur = prev;
		}
		prev = cur;
		if (cur->next)
			cur = cur->next;
	}
	if (cur == NULL)
		free_me(cur);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		return (-1);
	}
	return (fd);
}
