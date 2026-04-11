/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:29:16 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/02 14:13:52 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*src;
	char	*result;
	char	sc;
	int		i;

	src = (char *)str;
	sc = (char)c;
	i = 0;
	result = 0;
	while (src[i] != '\0')
	{
		if (src[i] == sc)
			result = src + i;
		i++;
	}
	if (src[i] == sc)
		return (src + i);
	else
		return (result);
}
