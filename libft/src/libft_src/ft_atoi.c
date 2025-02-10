/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 05:54:58 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 19:58:31 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

static int	ft_check_overflow(long long res, int sign, char next_digit)
{
	if (res > (LONG_MAX - (next_digit - '0')) / 10)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	long long		res;
	size_t			i;
	int				sign;
	int				overflow_check;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		overflow_check = ft_check_overflow(res, sign, str[i]);
		if (overflow_check != 1)
			return (overflow_check);
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (sign * (int)res);
}
