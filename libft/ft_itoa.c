/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:18:34 by frajaona          #+#    #+#             */
/*   Updated: 2024/03/02 15:52:32 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getnb(int n)
{
	size_t	i;

	i = 1;
	n = n / 10;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		nb;
	long int	num;

	num = n;
	nb = ft_getnb(n);
	if (n < 0)
	{
		num = num * -1;
		nb++;
	}
	str = (char *)malloc(sizeof(char) * (nb + 1));
	if (str == 0)
		return (0);
	str[nb] = 0;
	while (nb--)
	{
		str[nb] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
