/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 22:04:49 by aybelaou          #+#    #+#             */
/*   Updated: 2024/11/29 22:04:49 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/gnl_inc/get_next_line.h"

// This function removes the returned line from the 
//	stored data and keeps any remaining data for the next call.

//     It finds the last node in the list.
//     Allocates a new buffer and a new node for the remaining data.
//     Copies the remaining data (after the newline) to the new buffer.
//     Frees the old list and sets the new node as the head of the list

void	reset_list(t_charlist **list)
{
	t_charlist	*last;
	t_charlist	*n;
	char		*b;
	int			i;
	int			len;

	last = ft_charlstlast(*list);
	if (!list || !*list || !last || !last->content)
		return ;
	b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (free(b), free_charlist(list, NULL, NULL));
	n = malloc(sizeof(t_charlist));
	if (!n)
		return (free(b), free_charlist(list, NULL, NULL));
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	len = 0;
	while (last->content[i])
		b[len++] = last->content[i++];
	b[len] = '\0';
	return (n->content = b, n->next = NULL, free_charlist(list, n, b));
}

// This function extracts the next line 
//	from the stored data in the list.

//     It calculates the length of the line using len_line.
//     Allocates memory for the line.
//     Copies the line from the list to the newly
//		allocated string using strcpy_nl.
//     Returns the extracted line.

char	*fetch_line(t_charlist *list)
{
	char	*line;
	int		len;

	if (!list)
		return (NULL);
	len = len_line(list);
	if (len <= 0)
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	strcpy_nl(list, line);
	return (line);
}

// This function adds a new node 
//	to the end of the linked list.

//     It allocates memory for a new node.
//     Sets the content of the new node to the provided buffer.
//     If the list is empty, it sets the new node as the head of the list.
//     Otherwise, it appends the new node to the end of the list.

void	add_to_list(t_charlist **list, char *buf)
{
	t_charlist	*new_node;

	new_node = malloc(sizeof(t_charlist));
	if (!new_node)
	{
		free(buf);
		return ;
	}
	new_node->content = buf;
	new_node->next = NULL;
	if (!*list)
		*list = new_node;
	else
		ft_charlstlast(*list)->next = new_node;
}

// This function reads data from the file descriptor 
// 	and stores it in the linked list.

//     It allocates a buffer of size BUFFER_SIZE + 1.
//     It reads from the file descriptor in a loop 
//	   	until a newline is found or EOF is reached.
//     Each read chunk is added to the list using add_to_list.
//     If any memory allocation fails or read error occurs,
//	   	it frees the list and returns.

void	create_list(t_charlist **list, int fd)
{
	char	*buf;
	int		bytes_read;

	while (!found_nl(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
		{
			free(buf);
			free_charlist(list, NULL, NULL);
			return ;
		}
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buf);
			if (bytes_read < 0)
				free_charlist(list, NULL, NULL);
			return ;
		}
		buf[bytes_read] = '\0';
		add_to_list(list, buf);
	}
}

// This is the main function that returns
//	the next line from the file descriptor.

//     It first checks if the file descriptor 
//		is valid and if BUFFER_SIZE is positive.
//     It calls create_list to read data from the file descriptor.
//     If the list is empty after creation, it returns NULL.
//     It then calls fetch_line to extract 
//		the next line from the stored data.
//     If fetch_line returns NULL, it frees the list and returns NULL.
//     Finally, it calls reset_list to remove
//		the returned line from the stored data.
//     Returns the extracted line.

char	*get_next_line(int fd)
{
	static t_charlist	*list = NULL;
	char				*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free_charlist(&list, NULL, NULL);
		return (NULL);
	}
	create_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = fetch_line(list);
	if (!next_line)
	{
		free_charlist(&list, NULL, NULL);
		return (NULL);
	}
	reset_list(&list);
	return (next_line);
}
