/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:49:15 by awissade          #+#    #+#             */
/*   Updated: 2024/02/04 17:47:43 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	int	bits_read;
	int	mode;
	int	client_pid;
}	t_data;

int		ft_atoi(const char *str);
void	ft_putnbr(int n);
char	*ft_itoa(int n);

#endif
