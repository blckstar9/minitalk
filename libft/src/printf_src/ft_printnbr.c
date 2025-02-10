/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:00:37 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:19 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	number_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		if (ft_printchar('-') == -1)
			return (-1);
		nb = -nb;
	}
	if (nb > 9)
	{
		if (ft_putnbr(nb / 10) == -1)
			return (-1);
	}
	if (ft_printchar((nb % 10) + '0') == -1)
		return (-1);
	return (0);
}

int	ft_printnbr(int n)
{
	int	len;

	len = number_len(n);
	if (ft_putnbr(n) == -1)
		return (-1);
	return (len);
}
