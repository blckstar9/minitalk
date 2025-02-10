/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:07:50 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:10 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printchar(const char c)
{
	return (ft_putchar(c));
}
