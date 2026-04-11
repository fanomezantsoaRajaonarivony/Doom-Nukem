/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:31:01 by frajaona          #+#    #+#             */
/*   Updated: 2024/08/01 00:45:35 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	point(va_list *ptr, int len)
{
	unsigned long int	point;

	point = va_arg(*ptr, unsigned long int);
	if (point == 0)
		len += write(1, "(nil)", 5);
	else
	{
		len += write(1, "0x", 2);
		len += print_point(point);
	}
	return (len);
}

int	ft_checker(char c, va_list *ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_char(va_arg(*ptr, int));
	else if (c == 's')
		len += print_str(va_arg(*ptr, char *));
	else if (c == 'p')
		len += point(ptr, len);
	else if (c == 'd' || c == 'i')
		len += print_nb(va_arg(*ptr, int));
	else if (c == 'u')
		len += print_unb(va_arg(*ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		len += print_hex(va_arg(*ptr, unsigned int), c);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}
