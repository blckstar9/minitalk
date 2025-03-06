/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:44:55 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/06 18:13:10 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include "../libft/inc/libft_inc/libft.h"
# include "../libft/inc/gnl_inc/get_next_line.h"
# include "../libft/inc/printf_inc/ft_printf.h"

# define RED "\033[31m"
# define RS "\033[0m"
# define CY "\033[36m"
# define YL "\033[33m"
# define GR "\033[32m"
# define MG "\033[35m"

typedef struct s_state
{
	int				bit_count;
	unsigned char	character;
}	t_state;

#endif