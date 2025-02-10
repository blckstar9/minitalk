/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:17:04 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:26 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	char	*unoffset_str;

	if (!s1 || !s2)
		return (NULL);
	joined_str = (char *)ft_calloc(
			(ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!joined_str)
		return (NULL);
	unoffset_str = joined_str;
	while (*s1)
		*(joined_str++) = *(s1++);
	while (*s2)
		*(joined_str++) = *(s2++);
	return (unoffset_str);
}
