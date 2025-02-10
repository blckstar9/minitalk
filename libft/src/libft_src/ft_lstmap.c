/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:24:35 by aybelaou          #+#    #+#             */
/*   Updated: 2025/01/31 17:30:25 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

t_voidlist	*ft_lstmap(t_voidlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_voidlist	*n_list;
	t_voidlist	*n_obj;
	void		*new_content;

	if (!lst || !f || !del)
		return (NULL);
	n_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		n_obj = ft_lstnew(new_content);
		if (!n_obj)
		{
			del(new_content);
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		ft_lstadd_back(&n_list, n_obj);
		lst = lst->next;
	}
	return (n_list);
}
