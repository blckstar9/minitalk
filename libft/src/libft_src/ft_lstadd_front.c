/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:01:11 by aybelaou          #+#    #+#             */
/*   Updated: 2024/12/20 15:02:15 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft_inc/libft.h"

void	ft_lstadd_front(t_voidlist **lst, t_voidlist *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}
