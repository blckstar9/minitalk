/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:59:25 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:12 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

static size_t	count_words(const char *s, char sep)
{
	size_t		count;
	const char	*str;

	if (!s)
		return (0);
	count = 0;
	str = s;
	while (*str)
	{
		while (*str && (*str == sep))
			str++;
		if (*str)
			count++;
		while (*str && !(*str == sep))
			str++;
	}
	return (count);
}

static size_t	len_word(const char *s, char sep)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && !(s[len] == sep))
		len++;
	return (len);
}

static char	*create_word(const char *s, char sep)
{
	size_t	len;
	char	*word;
	char	*unoffset_word;

	len = len_word(s, sep);
	word = (char *)ft_calloc((len + 1), sizeof(char));
	if (!word)
		return (NULL);
	unoffset_word = word;
	while (len-- > 0)
		*(word++) = *(s++);
	return ((char *)unoffset_word);
}

static char	**free_split(char **tab)
{
	char	**unoffset_tab;

	unoffset_tab = tab;
	while (*unoffset_tab)
		free(*unoffset_tab++);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	**unoffset_tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	unoffset_tab = tab;
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			*tab = create_word(s, c);
			if (!*tab)
				return (free_split(unoffset_tab));
			tab++;
		}
		while (*s && !(*s == c))
			s++;
	}
	*tab = NULL;
	return (unoffset_tab);
}
