/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:12:25 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/19 20:00:41 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	len;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	new_s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	while (len-- > 0)
		new_s[len] = (*f)(len, s[len]);
	return (new_s);
}
