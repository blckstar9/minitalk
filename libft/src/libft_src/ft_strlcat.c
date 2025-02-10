/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:35:59 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:30 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (lendst >= dstsize)
		lendst = dstsize;
	if (dstsize == lendst)
		return (lendst + lensrc);
	if (lensrc < dstsize - lendst)
		ft_memcpy(dst + lendst, src, lensrc + 1);
	else
	{
		ft_memcpy(dst + lendst, src, dstsize - lendst - 1);
		dst[dstsize - 1] = 0;
	}
	return (lendst + lensrc);
}
