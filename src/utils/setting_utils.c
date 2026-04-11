/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:49:50 by frajaona          #+#    #+#             */
/*   Updated: 2025/04/23 09:07:30 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	convert_color(char *str)
{
	int	sum;
	int	i;
	int	j;
	int	verif;

	sum = 0;
	i = 2;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			i++;
		verif = 0;
		j = i;
		while (str[j] >= '0' && str[j] <= '9' && str[j] != ',')
		{
			verif = (verif * 10) + str[j] - 48;
			sum = (sum * 10) + (str[j] - 48);
			j++;
		}
		i = j;
		if (verif > 255 || verif < 0)
			return (-1);
	}
	return (sum);
}

int	len_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	get_start(char c, t_player *get, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		get->start = c;
		get->dx = i;
		get->dy = j;
		return (1);
	}
	return (0);
}

int	copy_map(char *str, t_cube *get, int i)
{
	int		j;
	t_map	*maps;

	j = 0;
	maps = &get->map;
	if (str == NULL)
		return (0);
	maps->map[i] = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!maps->map[i])
		return (1);
	while (str[j] != '\0')
	{
		if (get_start(str[j], &get->player, i, j) == 1)
			maps->map[i][j] = '0';
		else if (str[j] == ' ')
			maps->map[i][j] = '1';
		else
			maps->map[i][j] = str[j];
		j++;
	}
	maps->map[i][j] = '\0';
	return (0);
}

int	id_strstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0] && s1[i + 1] == s2[1])
			return (1);
		i++;
	}
	return (0);
}
