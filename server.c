/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:34:15 by awissade          #+#    #+#             */
/*   Updated: 2024/02/01 09:34:16 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_bits_count;

void	process_signal(int getnum)
{
	static char	current_character;

	if (getnum == SIGUSR1)
		current_character |= (1 << (7 - g_bits_count));
	else if (getnum == SIGUSR2)
		current_character |= (0 << (7 - g_bits_count));
	g_bits_count++;
	if (g_bits_count == 8)
	{
		write(1, &current_character, 1);
		current_character = 0;
		g_bits_count = 0;
	}
}

int	main(void)
{
	int	pid;

	write(1, "WELCOME TO MINITALK\n", 20);
	pid = getpid();
	write(1, "process id: ", 12);
	ft_putnbr(pid);
	signal(SIGUSR1, process_signal);
	signal(SIGUSR2, process_signal);
	while (1)
	{
	}
	return (0);
}
