/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 19:57:32 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/03 17:38:18 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

// // Sends the specified message to the specified
// // process using SIGUSR1 and SIGUSR2 signals
// // Iterate through each character of the message
// // Iterate through each bit of the current character
// // If the current bit is 1, send SIGUSR1 signal;
// // otherwise, send SIGUSR2 signal
// // Sleep for 100 microseconds between each signal
// void	signal_action(int pid, char *str)


int	g_server_pid = 0;

void	signal_action(int pid, char *str)
{
	int	i;
	int	c;

	while (*str)
	{
		c = *(str);
		i = 0;
		while (i < 8)
		{
			if (c & 0b10000000)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("Unable to send SIGUSR1\n");
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_printf("Unable to send SIGUSR2\n");
			}
			c <<= 1;
			usleep(100);
			i++;
		}
		str++;
	}
}

void	handler(int sig)
{
	static int	message_printed = 0;

	if (!message_printed)
	{
		if (sig == SIGUSR1)
		{
			ft_printf("The signal was received successfully.\n");
			message_printed = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_sig;
	int					i;

	if (argc != 3 || !argv[2])
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			if (argv[1][i++] == '\0')
				return (ft_printf("Invalid PID.\n"), EXIT_FAILURE);
	g_server_pid = ft_atoi(argv[1]);
	if (g_server_pid <= 0)
		return (ft_printf("Invalid PID.\n"), EXIT_FAILURE);
	sa_sig.sa_handler = &handler;
	sa_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	signal_action(g_server_pid, argv[2]);
	return (EXIT_SUCCESS);
}
