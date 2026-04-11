/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:10:39 by frajaona          #+#    #+#             */
/*   Updated: 2024/08/01 00:45:42 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_point(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_point(nb / 16);
		len += print_point(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + '0');
		else
			len += print_char(nb + 87);
	}
	return (len);
}

int	print_nb(int nb)
{
	long long	n;
	int			len;

	n = nb;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += print_nb(n / 10);
		len += print_nb(n % 10);
	}
	if (n < 10)
		len += print_char(n + '0');
	return (len);
}

int	print_unb(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += print_unb(nb / 10);
		len += print_unb(nb % 10);
	}
	if (nb < 10)
		len += print_char(nb + '0');
	return (len);
}

int	print_hex(unsigned int nb, char c)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += print_hex(nb / 16, c);
		len += print_hex(nb % 16, c);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += print_char(nb + '0');
		else
		{
			if (c == 'x')
				len += print_char(nb + 87);
			else if (c == 'X')
				len += print_char(nb + 55);
		}
	}
	return (len);
}
