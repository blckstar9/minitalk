/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:58:26 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 19:59:48 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	if (!dst && !src)
		return (dst);
	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	while (n-- > 0)
		*(tmpd++) = *(tmps++);
	return (dst);
}
