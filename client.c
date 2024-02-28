/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:34:05 by awissade          #+#    #+#             */
/*   Updated: 2024/02/08 09:27:31 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	check_pid(int server_pid)
{
	if (server_pid <= 0)
	{
		write(1, "The PID is invalid\n", 19);
		exit(1);
	}
}

void	send_character(int server_pid, char *str)
{
	int	message_index;
	int	bit_index;
	int	kill_result;

	message_index = 0;
	while (str[message_index])
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			if (str[message_index] & (1 << (7 - bit_index)))
				kill_result = kill(server_pid, SIGUSR1);
			else
				kill_result = kill(server_pid, SIGUSR2);
			usleep(100);
			if (kill_result == -1)
			{
				write(1, "The PID is invalid\n", 19);
				exit(1);
			}
			bit_index++;
		}
		message_index++;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
	{
		write(1, "Number of arguments must be 3\n", 30);
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	check_pid(server_pid);
	send_character(server_pid, av[2]);
	send_character(server_pid, "\n");
	return (0);
}
