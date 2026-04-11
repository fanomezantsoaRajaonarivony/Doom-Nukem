/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:35:16 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/02 14:18:05 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*duplicate;

	i = 0;
	duplicate = (char *)malloc(ft_strlen(s) + 1);
	if (s == 0 || duplicate == 0)
		return (0);
	if (duplicate != 0)
	{
		while (s[i] != '\0')
		{
			duplicate[i] = s[i];
			i++;
		}
	}
	duplicate[i] = '\0';
	return (duplicate);
}
