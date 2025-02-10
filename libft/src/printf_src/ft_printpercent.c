/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:22:49 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:04:22 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/printf_inc/ft_printf.h"

static int	ft_putpercent(void)
{
	return (ft_printchar('%'));
}

int	ft_printpercent(void)
{
	return (ft_putpercent());
}
