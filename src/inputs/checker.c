/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:47:39 by frajaona          #+#    #+#             */
/*   Updated: 2025/03/19 10:05:20 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	analyze_extension(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len != 4)
		return (-1);
	if (ft_strcmp(str, ".cub"))
		return (-1);
	return (0);
}

int	check_args(char *av)
{
	int		i;
	char	*occ;

	i = 0;
	occ = ft_strrchr(&av[i], '.');
	if (!occ)
	{
		ft_putstr_fd("Error\nMap extension must be .cub\n", 2);
		return (-1);
	}
	if (analyze_extension(occ) == 0)
		return (0);
	else
	{
		ft_putstr_fd("Error\nMap extension must be .cub\n", 2);
		return (-1);
	}
	return (0);
}

int	check_error(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		return (-1);
	}
	if (check_args(path) == -1)
	{
		close(fd);
		return (-1);
	}
	return (fd);
}

int	check_player(char c)
{
	char	*valid;

	valid = "NSEW";
	while (*valid)
	{
		if (*valid == c)
			return (1);
		valid++;
	}
	return (0);
}
