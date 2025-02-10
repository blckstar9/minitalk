/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:33:17 by aybelaou          #+#    #+#             */
/*   Updated: 2024/11/28 20:33:17 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gnl_inc/get_next_line.h"

// This function returns the last node of the linked list.

t_charlist	*ft_charlstlast(t_charlist *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

// This function checks if a newline character exists in the list.

int	found_nl(t_charlist *list)
{
	int	i;

	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n' || list->content[i] == '\0')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

// This function calculates the length of the next line in the list.
int	len_line(t_charlist *list)
{
	int	len;
	int	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			len++;
			if (list->content[i] == '\n')
				return (len);
			i++;
		}
		list = list->next;
	}
	return (len);
}

// This function copies characters from the list
//	 to the line string, stopping at a newline character.

void	strcpy_nl(t_charlist *list, char *line)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		if (!list->content)
		{
			list = list->next;
			continue ;
		}
		i = 0;
		while (list->content[i])
		{
			line[len++] = list->content[i];
			if (list->content[i] == '\n')
			{
				line[len] = '\0';
				return ;
			}
			i++;
		}
		list = list->next;
	}
	line[len] = '\0';
}

// This function frees the memory allocated for the list
//	and sets a new list head.

void	free_charlist(t_charlist **list, t_charlist *new, char *cleanbuf)
{
	t_charlist	*cleaner;

	while (list && *list)
	{
		cleaner = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = cleaner;
	}
	if (list)
		*list = NULL;
	if (new && new->content && new->content[0])
		*list = new;
	else
	{
		free(new);
		free(cleanbuf);
	}
}
