/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:48:55 by frajaona          #+#    #+#             */
/*   Updated: 2024/08/01 00:46:17 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(num_elements * element_size);
	if (!ptr)
		return (0);
	while (i < num_elements * element_size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
