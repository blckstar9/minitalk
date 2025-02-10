/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:27:12 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:13 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	process_char(const char **format, va_list args)
{
	int	exit_code;

	if (**format == '%')
	{
		(*format)++;
		exit_code = ft_format(args, **format);
	}
	else
		exit_code = ft_printchar(**format);
	return (exit_code);
}

static int	handle_exit_code(int *len, int exit_code)
{
	if (exit_code == -1)
		return (-1);
	*len += exit_code;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		exit_code;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		exit_code = process_char(&format, args);
		if (handle_exit_code(&len, exit_code) == -1)
			return (-1);
		format++;
	}
	va_end(args);
	return (len);
}
