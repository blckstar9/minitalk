/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:16:55 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/09 22:26:05 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk_bonus.h"

volatile t_state	g_state = {0, 0};

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
		if (g_state.character == 0)
			ft_putchar_fd('\n', 1);
		else
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

void	terminate_handler(int sig)
{
	if (sig == SIGINT)
		ft_printf(GR"\nServer shutting down (SIGINT received)...\n"RS);
	else if (sig == SIGTERM)
		ft_printf(GR"\nServer shutting down (SIGTERM received)...\n"RS);
	else
		ft_printf(GR"\nServer shutting down (signal %d received)...\n"RS, sig);
	exit(0);
}

int	main(void)
{
	struct sigaction	sa_struct;

	ft_printf(GR "PID: %d\n" RS, getpid());
	sa_struct.sa_sigaction = &sig_handler;
	sa_struct.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_struct.sa_mask);
	sigaddset(&sa_struct.sa_mask, SIGUSR1);
	sigaddset(&sa_struct.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa_struct, NULL) == -1)
		ft_putstr_fd(RED "Error\nUnable to set SIGUSR1 handler\n" RS, 2);
	if (sigaction(SIGUSR2, &sa_struct, NULL) == -1)
		ft_putstr_fd(RED "Error\nUnable to set SIGUSR2 handler\n" RS, 2);
	signal(SIGINT, terminate_handler);
	signal(SIGTERM, terminate_handler);
	while (1)
		pause();
	return (0);
}
