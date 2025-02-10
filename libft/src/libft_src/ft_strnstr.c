/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:04:50 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:50 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		nlen;
	size_t		rlen;
	const char	*h;
	const char	*n;

	nlen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len >= nlen)
	{
		h = (const char *)haystack;
		n = (const char *)needle;
		rlen = len;
		while (*h == *n && *n && rlen--)
		{
			h++;
			n++;
		}
		if (!*n)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
