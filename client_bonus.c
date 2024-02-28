/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 13:51:47 by awissade          #+#    #+#             */
/*   Updated: 2024/02/08 09:14:18 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_message_sent;

void	check_pid(int server_pid)
{
	if (server_pid <= 0)
	{
		write(1, "The PID is invalid\n", 19);
		exit(1);
	}
}

void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Message sent successfully\n", 26);
		g_message_sent = 1;
	}
}

void	send_single_bit_to_server(int pid, unsigned char byte)
{
	int	bit_index;
	int	kill_result;

	bit_index = 0;
	while (bit_index < 8)
	{
		if (byte & (1 << (7 - bit_index)))
			kill_result = kill(pid, SIGUSR1);
		else
			kill_result = kill(pid, SIGUSR2);
		if (kill_result == -1)
		{
			write(1, "The PID is invalid\n", 19);
			exit(1);
		}
		usleep(100);
		bit_index++;
	}
}

void	send_bytes(int pid, char *str)
{
	int	byte_index;

	byte_index = 0;
	while (str[byte_index])
	{
		send_single_bit_to_server(pid, str[byte_index]);
		byte_index++;
	}
	send_single_bit_to_server(pid, '\0');
}

int	main(int ac, char **av)
{
	int		pid_server;
	char	*pid_client;

	if (ac != 3)
	{
		write(1, "Number of arguments must be 3\n", 30);
		return (1);
	}
	signal(SIGUSR1, handler);
	pid_server = ft_atoi(av[1]);
	pid_client = ft_itoa(getpid());
	check_pid(pid_server);
	send_bytes(pid_server, pid_client);
	send_bytes(pid_server, av[2]);
	while (!g_message_sent)
		(void)g_message_sent;
	free(pid_client);
	return (0);
}
