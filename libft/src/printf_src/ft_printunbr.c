/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:08:17 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:05:33 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	unsigned_number_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putunbr(unsigned int n)
{
	if (n > 9)
	{
		if (ft_putunbr(n / 10) == -1)
			return (-1);
	}
	if (ft_printchar((n % 10) + '0') == -1)
		return (-1);
	return (0);
}

int	ft_printunbr(unsigned int n)
{
	int	len;

	len = unsigned_number_len(n);
	if (ft_putunbr(n) == -1)
		return (-1);
	return (len);
}
