/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:10:20 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:27 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	ft_putstr(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (ft_printchar(*(s++)) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_printstr(const char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = ft_putstr(s);
	if (len == -1)
		return (-1);
	return (len);
}
