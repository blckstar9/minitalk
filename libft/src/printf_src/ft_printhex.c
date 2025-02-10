/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:06:15 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:16 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	hex_number_len(uintptr_t hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		return (1);
	while (hex > 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

static int	ft_puthex(uintptr_t hex, const char c)
{
	char	hex_digit;

	if (hex == 0)
	{
		return (ft_printchar('0'));
	}
	if (hex >= 16)
	{
		if (ft_puthex(hex / 16, c) == -1)
			return (-1);
	}
	hex_digit = "0123456789abcdef"[hex % 16];
	if (c == 'X' && hex_digit >= 'a' && hex_digit <= 'f')
		hex_digit -= 32;
	return (ft_printchar(hex_digit));
}

int	ft_printhex(uintptr_t hex, const char c)
{
	int	len;

	len = hex_number_len(hex);
	if (ft_puthex(hex, c) == -1)
		return (-1);
	return (len);
}
