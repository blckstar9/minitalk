/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:22:39 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:54 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ptr = NULL;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			ptr = (char *)s;
		++s;
	}
	if (*s == ch)
		ptr = (char *)s;
	return (ptr);
}
