/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:06:55 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:25 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	pointer_len(uintptr_t ptr)
{
	int	len;

	len = 2;
	if (ptr == 0)
		return (len + 1);
	while (ptr)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static int	ft_putptr(uintptr_t ptr)
{
	if (ptr == 0)
		return (ft_printstr("0x0"));
	if (ft_printstr("0x") == -1)
		return (-1);
	if (ft_printhex(ptr, 'x') == -1)
		return (-1);
	return (0);
}

int	ft_printptr(void *ptr)
{
	uintptr_t	pointer;
	int			len;

	pointer = (uintptr_t)ptr;
	len = pointer_len(pointer);
	if (ft_putptr(pointer) == -1)
		return (-1);
	return (len);
}
