/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:57:40 by awissade          #+#    #+#             */
/*   Updated: 2024/02/01 13:57:56 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_whitespace(const char *str)
{
	int	index;

	index = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	return (index);
}

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	result;

	sign = 1;
	index = is_whitespace(str);
	if ((str[index] == '-' || str[index] == '+')
		&& (str[index + 1] == '-' || str[index + 1] == '+'))
		return (0);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = sign * -1;
		index++;
	}
	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result + (str[index] - '0');
		if (str[index + 1] >= '0' && str[index + 1] <= '9')
			result = result * 10;
		index++;
	}
	return (result * sign);
}
