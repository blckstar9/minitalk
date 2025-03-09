/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:17:05 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/09 22:25:52 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

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
