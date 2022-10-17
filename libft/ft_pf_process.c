/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 11:11:29 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/09 20:16:15 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_va_putnbr_add_util(size_t *nbr, int *len, int base)
{
	*len = 0;
	if (base == 16)
	{
		*len += ft_putstr_rt("0x");
		if (*nbr < 0)
			*nbr = ULLONG_MAX - (-(*nbr));
	}
}

static void	ft_va_putnbr_util(ssize_t *nbr, int *len, int base)
{
	*len = 0;
	if (base < 16 && *nbr < 0)
	{
		*len += ft_putchar_rt('-');
		if (*nbr == INT_MIN)
		{
			*len += ft_putstr_rt("2147483648");
			*nbr = -1;
		}
		else
			*nbr *= -1;
	}
	else if (base == 16)
		if (*nbr < 0)
			*nbr = 4294967296 - (-(*nbr));
}

static int	ft_va_putnbr_add(size_t nbr, int base)
{
	int		rt_len;
	int		index;
	char	str_nbr[23];

	index = 0;
	ft_va_putnbr_add_util(&nbr, &rt_len, base);
	while (nbr >= 0)
	{
		str_nbr[index++] = "0123456789abcdef"[(nbr % base)];
		nbr /= base;
		if (nbr == 0)
			break ;
	}
	str_nbr[index] = '\0';
	while (index)
		rt_len += ft_putchar_rt(str_nbr[--index]);
	return (rt_len);
}

static int	ft_va_putnbr(ssize_t nbr, int base, int capital)
{
	int		rt_len;
	int		index;
	char	str_nbr[23];

	index = 0;
	ft_va_putnbr_util(&nbr, &rt_len, base);
	while (nbr >= 0)
	{
		if (capital)
			str_nbr[index++] = "0123456789abcdef"[(nbr % base)];
		else
			str_nbr[index++] = "0123456789ABCDEF"[(nbr % base)];
		nbr /= base;
		if (nbr == 0)
			break ;
	}
	str_nbr[index] = '\0';
	while (index)
		rt_len += ft_putchar_rt(str_nbr[--index]);
	return (rt_len);
}

int	ft_pf_process(va_list ap, char type)
{
	if (type == 'c')
		return (ft_putchar_rt(va_arg(ap, int)));
	else if (type == 's')
		return (ft_putstr_rt(va_arg(ap, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_va_putnbr(va_arg(ap, int), 10, 0));
	else if (type == 'u')
		return (ft_va_putnbr_add(va_arg(ap, unsigned int), 10));
	else if (type == 'x')
		return (ft_va_putnbr(va_arg(ap, int), 16, 1));
	else if (type == 'X')
		return (ft_va_putnbr(va_arg(ap, int), 16, 0));
	else if (type == 'p')
		return (ft_va_putnbr_add(va_arg(ap, size_t), 16));
	else if (type == '%')
		return (ft_putchar_rt('%'));
	return (0);
}
