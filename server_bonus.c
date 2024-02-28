/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:51:57 by awissade          #+#    #+#             */
/*   Updated: 2024/02/08 09:39:11 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	handle_character(char *character)
{
	if (*character)
	{
		if (g_data.mode == 0)
			g_data.client_pid = g_data.client_pid * 10 + (*character - '0');
		else if (g_data.mode == 1)
			write(1, character, 1);
	}
	else
	{
		g_data.mode++;
		if (g_data.mode == 2)
		{
			write(1, "\n", 1);
			kill(g_data.client_pid, SIGUSR1);
			g_data.client_pid = 0;
			g_data.mode = 0;
		}
	}
	*character = 0;
	g_data.bits_read = 0;
}

void	process_signal_bonus(int received_signal)
{
	static char	character;

	if (received_signal == SIGUSR1)
		character |= (1 << (7 - g_data.bits_read));
	else if (received_signal == SIGUSR2)
		character |= (0 << (7 - g_data.bits_read));
	g_data.bits_read++;
	if (g_data.bits_read == 8)
		handle_character(&character);
}

int	main(void)
{
	int	pid;

	write(1, "WELCOME TO MINITALK BONUS\n", 26);
	pid = getpid();
	write(1, "process id: ", 12);
	ft_putnbr(pid);
	signal(SIGUSR1, process_signal_bonus);
	signal(SIGUSR2, process_signal_bonus);
	while (1)
		(void)pid;
	return (0);
}
