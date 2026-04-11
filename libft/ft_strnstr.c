/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:23:41 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/04 12:13:57 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	len;
	char	*src;
	char	*dst;
	int		i;

	i = 0;
	if (s1 == 0 && n == 0)
		return (0);
	src = (char *)s1;
	dst = (char *)s2;
	if (dst[i] == 0)
		return (src);
	len = ft_strlen(dst);
	while (src[i] != 0 && n >= len)
	{
		if (ft_strncmp(src, dst, len) == 0)
			return (src);
		src++;
		n--;
	}
	return (0);
}
