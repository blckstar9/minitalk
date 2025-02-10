/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 04:42:53 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 19:59:52 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;
	size_t			count;

	if (!dst && !src)
		return (NULL);
	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	count = -1;
	if (tmpd > tmps)
		while (len-- > 0)
			tmpd[len] = tmps[len];
	else
		while (++count < len)
			tmpd[count] = tmps[count];
	return (dst);
}
