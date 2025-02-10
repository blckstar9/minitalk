/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 06:51:50 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:18 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	char	*unoffset_s2;

	len = ft_strlen(s1);
	s2 = (char *)ft_calloc((len + 1), sizeof(char));
	if (!s2)
		return (NULL);
	unoffset_s2 = s2;
	while (len-- > 0)
		*(s2++) = (char)*(s1++);
	return ((char *)unoffset_s2);
}
