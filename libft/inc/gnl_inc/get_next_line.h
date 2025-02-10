/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:17:22 by aybelaou          #+#    #+#             */
/*   Updated: 2024/11/29 18:17:22 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_charlist
{
	char				*content;
	struct s_charlist	*next;
}	t_charlist;
t_charlist	*ft_charlstlast(t_charlist *lst);
int			found_nl(t_charlist *list);
int			len_line(t_charlist *list);
void		strcpy_nl(t_charlist *list, char *line);
void		free_charlist(t_charlist **list, t_charlist *new, char *cleanbuf);
char		*get_next_line(int fd);
#endif
