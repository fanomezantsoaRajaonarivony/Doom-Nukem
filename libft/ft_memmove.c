/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:21:52 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/04 12:07:33 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*result;

	if ((!dest && !src) || (dest == src))
		return (dest);
	result = dest;
	if (dest > src)
	{
		while (n != 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
	{
		while (n != 0)
		{
			n--;
			*(char *)dest++ = *(char *)src++;
		}
	}
	return (result);
}
