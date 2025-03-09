/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:54:52 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/09 17:55:19 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	handle_failure(int *fails, char *message)
{
	(*fails)++;
	if (*fails >= 5)
	{
		ft_putstr_fd(RED"Error\n", 2);
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n"RS, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
