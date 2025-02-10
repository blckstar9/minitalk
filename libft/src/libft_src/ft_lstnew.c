/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:42:55 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/20 15:03:41 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

t_voidlist	*ft_lstnew(void *content)
{
	t_voidlist	*list;

	list = malloc(sizeof(t_voidlist));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
