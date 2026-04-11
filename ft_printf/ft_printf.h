/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frajaona <frajaona@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:34:59 by frajaona          #+#    #+#             */
/*   Updated: 2024/08/01 00:45:45 by frajaona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_char(char c);
int	print_str(char *str);
int	print_point(unsigned long int nb);
int	print_nb(int nb);
int	print_unb(unsigned int nb);
int	print_hex(unsigned int nb, char s);
int	ft_checker(char c, va_list *ptr);
int	ft_printf(const char *format, ...);

#endif
