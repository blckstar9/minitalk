/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:57:32 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/09 18:03:30 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

volatile sig_atomic_t	g_sig_received = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf(GR"Character received successfully.\n"RS);
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		g_sig_received = 1;
	}
}

int	send_bit(int pid, int bit)
{
	int			timeout_count;
	static int	fails = 0;
	int			sig;

	timeout_count = 0;
	g_sig_received = 0;
	if (bit)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	if (kill(pid, sig) == -1)
		return (handle_failure(&fails, "Process not responding"));
	while (!g_sig_received && timeout_count < 1000)
	{
		usleep(100);
		timeout_count++;
	}
	if (timeout_count >= 1000)
		return (handle_failure(&fails, "Server not responding"));
	fails = 0;
	return (1);
}

void	send_char(int pid, char c)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = !!(c & (0x80 >> i));
		if (!send_bit(pid, bit))
			i--;
		else
			i++;
	}
}

void	signal_action(int pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					pid;
	int					i;

	if (argc != 3 || !argv[2])
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			return (ft_putstr_fd(RED"Invalid PID.\n"RS, 2), EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_putstr_fd(RED"Invalid PID.\n"RS, 2), EXIT_FAILURE);
	sa_sig.sa_handler = &handler;
	sa_sig.sa_flags = 0;
	sigemptyset(&sa_sig.sa_mask);
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	ft_printf(GR"Sending message to PID %d...\n"RS, pid);
	signal_action(pid, argv[2]);
	ft_printf(GR"Message sent successfully.\n"RS);
	return (EXIT_SUCCESS);
}
