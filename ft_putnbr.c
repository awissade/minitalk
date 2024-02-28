/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:25:25 by awissade          #+#    #+#             */
/*   Updated: 2024/02/04 17:48:28 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	long	number;
	long	divisor;
	char	digit;

	number = n;
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}
	divisor = 1;
	while (number / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		digit = '0' + (number / divisor);
		write(1, &digit, 1);
		number = number % divisor;
		divisor /= 10;
	}
	write (1, "\n", 1);
}
