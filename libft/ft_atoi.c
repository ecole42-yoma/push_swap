/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:00:13 by yongmkim          #+#    #+#             */
/*   Updated: 2021/07/14 16:20:47 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	char	*space;

	space = "\t\n\v\f\r ";
	while (*space)
	{
		if (c == *space)
			return (TRUE);
		space++;
	}
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	unsigned long long	sum;
	int					sign;

	sum = 0;
	sign = 1;
	while (ft_isspace(*str) && (*str != 0))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		sum = (sum * 10) + (*str - '0');
		str++;
	}
	if (sum > LONG_MAX && sign == 1)
		return (-1);
	if (sum - 1 > LONG_MAX && sign == -1)
		return (0);
	return (sign * sum);
}
