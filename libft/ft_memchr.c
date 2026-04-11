/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:46:44 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/02 14:15:35 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	char	uc;
	size_t	i;

	p = (char *)s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (p[i] == uc)
		{
			return (p + i);
		}
		i++;
	}
	return (0);
}
