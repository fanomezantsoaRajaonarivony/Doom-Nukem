/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:15:48 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/18 13:48:07 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

void	free_error(char *line, t_file *head)
{
	ft_putstr_fd("Error\nOnly use space\n", 2);
	free_file(head);
	free(line);
}

t_file	*compile_line(int fd, t_file *head, t_file *cur, int count)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if ((line[0] == '\0') && (count < 7))
		{
			free(line);
			continue ;
		}
		if (search_for_tab(line) == -1)
		{
			free_error(line, head);
			return (NULL);
		}
		count++;
		copy_file(cur, line);
		cur = cur->next;
		free(line);
	}
	free(line);
	return (cur);
}

t_file	*parse_file(int fd)
{
	t_file	*cur;
	t_file	*head;
	int		count;

	count = 0;
	cur = init_file();
	if (!cur)
		return (NULL);
	head = cur;
	cur = compile_line(fd, head, cur, count);
	if (!cur)
		return (NULL);
	cur->next = NULL;
	return (head);
}

int	search_for_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			return (-1);
		i++;
	}
	return (0);
}
