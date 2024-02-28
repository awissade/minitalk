/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awissade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:28:35 by awissade          #+#    #+#             */
/*   Updated: 2024/02/04 17:41:41 by awissade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_itoa(int n)
{
	char	*result_str;
	int		length;
	int		num;

	length = 0;
	num = n;
	while (num)
	{
		num /= 10;
		length++;
	}
	result_str = (char *)malloc((length + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	result_str[length] = '\0';
	length--;
	while (length >= 0)
	{
		result_str[length] = n % 10 + '0';
		n /= 10;
		length--;
	}
	return (result_str);
}
