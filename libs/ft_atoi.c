/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:58:27 by mpapin            #+#    #+#             */
/*   Updated: 2025/03/24 17:09:02 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs.h"
#include <limits.h>

static int	skipable(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static void	set_sign(char c, int *sign)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			*sign *= -1;
	}
}

int	ft_atoi(const char *str)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (skipable(str[i]))
		i++;
	set_sign(str[i], &sign);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	res = res * sign;
	if (res > INT_MAX)
		return (INT_MAX);
	if (res < INT_MIN)
		return (INT_MIN);
	return ((int) res);
}
