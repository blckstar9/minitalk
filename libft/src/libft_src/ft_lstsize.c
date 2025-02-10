/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:37:49 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/31 17:30:36 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

int	ft_lstsize(t_voidlist *lst)
{
	t_voidlist	*tmp;
	size_t		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	return ((int)i);
}
