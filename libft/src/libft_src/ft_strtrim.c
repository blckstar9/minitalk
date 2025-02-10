/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 22:11:06 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:59 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

static int	istrim(const char *set, const char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*clean_str(const char *s1, size_t start, size_t len)
{
	char	*trimmed_str;
	char	*unoffset_str;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	trimmed_str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!trimmed_str)
		return (NULL);
	unoffset_str = trimmed_str;
	while (len-- > 0)
		*(trimmed_str++) = *(s1 + start++);
	return ((char *)unoffset_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (istrim(set, s1[start]))
		++start;
	while (istrim(set, s1[end]))
		--end;
	return (clean_str(s1, start, end - (start - 1)));
}
