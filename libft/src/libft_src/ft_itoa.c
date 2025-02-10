/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:11:25 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 19:59:10 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

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

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*number;

	nb = n;
	len = number_len(nb);
	number = (char *)ft_calloc((len + 1), sizeof(char));
	if (!number)
		return (NULL);
	if (nb == 0)
	{
		number[0] = '0';
		return (number);
	}
	if (nb < 0)
	{
		number[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		number[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (number);
}
