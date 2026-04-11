/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokrandr <tokrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:29:33 by tokrandr          #+#    #+#             */
/*   Updated: 2025/03/12 14:36:19 by tokrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includs/cub.h"

int	check_valid_zero_col(char valid, char c)
{
	if (valid == c)
		return (1);
	return (0);
}

int	check_valid(char c)
{
	const char	*valid;

	valid = "01NSEW 	";
	while (*valid)
	{
		if (*valid == c)
			return (1);
		valid++;
	}
	return (0);
}
