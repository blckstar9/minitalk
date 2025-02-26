/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:57:24 by aybelaou          #+#    #+#             */
/*   Updated: 2025/02/26 23:41:45 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_state	g_state = {0, 0};

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2)
		g_state.character = g_state.character << 1;
	else if (sig == SIGUSR1)
		g_state.character = (g_state.character << 1) | 0b00000001;
	g_state.bit_count++;
	if (g_state.bit_count == 8)
	{
		ft_putchar_fd(g_state.character, 1);
		g_state.bit_count = 0;
		g_state.character = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr_fd(RED "Error\nUnable to send SIGUSR1\n" RS, 2);
		return ;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		ft_putstr_fd(RED "Error\nUnable to send SIGUSR2\n" RS, 2);
}

int	main(void)
{
	struct sigaction	sa_struct;

	ft_printf(GR "PID: %d\n" RS, getpid());
	while (1)
	{
		sa_struct.sa_sigaction = &sig_handler;
		sa_struct.sa_flags = SA_SIGINFO;
		sigemptyset(&sa_struct.sa_mask);
		sigaddset(&sa_struct.sa_mask, SIGUSR1);
		sigaddset(&sa_struct.sa_mask, SIGUSR2);
		if (sigaction(SIGUSR1, &sa_struct, NULL) == -1)
			ft_putstr_fd(RED "Error\nUnable to set SIGUSR1 handler\n" RS, 2);
		if (sigaction(SIGUSR2, &sa_struct, NULL) == -1)
			ft_putstr_fd(RED "Error\nUnable to set SIGUSR2 handler\n" RS, 2);
	}
	return (0);
}
