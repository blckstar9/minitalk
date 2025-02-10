/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:17:52 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:08 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

int	ft_format(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (c == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len = ft_printptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		len = ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_printunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len = ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len = ft_printpercent();
	if (len == -1)
		return (-1);
	return (len);
}
