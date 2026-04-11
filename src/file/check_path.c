/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 08:03:49 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/19 09:58:42 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	analyze_file_extenstion(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len != 4)
		return (-1);
	if (ft_strcmp(s, ".xpm") != 0)
		return (-1);
	return (0);
}

int	check_extension_error(char *s)
{
	char	*occ;

	occ = ft_strrchr(s, '.');
	if (!occ)
	{
		ft_putstr_fd("Error\nFile extension must be .xpm\n", 2);
		return (-1);
	}
	if (analyze_file_extenstion(occ) == 0)
		return (0);
	else
	{
		ft_putstr_fd("Error\nFile extension must be .xpm\n", 2);
		return (-1);
	}
	return (0);
}

int	open_texture(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile cannot be opened\n", 2);
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

int	tab_length(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			len += 4;
		else
			len++;
		i++;
	}
	return (len);
}
