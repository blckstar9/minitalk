/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:57:24 by aybelaou          #+#    #+#             */
/*   Updated: 2025/02/10 20:43:45 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int main(int ac, char **av)
{
	pid_t	servpid;

	servpid = getpid();
	if (servpid < 0)
	{
		ft_printf(RED "Error:\nBad PID given!\n" RS);
		exit(1);
	}
	ft_printf(GR "Server PID: %d\n" RS, servpid);
}