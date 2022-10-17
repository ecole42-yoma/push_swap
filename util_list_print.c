/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_list_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:06:33 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 11:56:33 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_list_max_min(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist		*temp;
	int			cnt;
	static int	max = MIN_INT;
	static int	min = MAX_INT;

	cnt = 2;
	while (cnt--)
	{
		if (cnt == 1)
			temp = *stack_a;
		else
			temp = *stack_b;
		while (temp)
		{
			if (temp->value > max)
				max = temp->value;
			if (temp->value < min)
				min = temp->value;
			temp = temp->next;
		}
	}
	if (ft_nbr_width(max) > ft_nbr_width(min))
		return (ft_nbr_width(max));
	return (ft_nbr_width(min));
}

static void	ft_print_nbr(t_dlist **head, t_print *t_info)
{
	size_t	cnt;
	size_t	width;

	cnt = 0;
	width = t_info->max_width - ft_nbr_width((*head)->value);
	while (++cnt <= width)
		ft_putchar_fd(' ', STD_OUT);
	ft_putnbr_fd((*head)->value, STD_OUT);
	*head = (*head)->next;
}

static void	ft_print_frame(t_dlist **head, t_print *t_info, int key)
{
	size_t	cnt;

	cnt = 0;
	if (key == 0 && (t_info->max_len - t_info->len_a == 0))
	{
		ft_print_nbr(head, t_info);
		t_info->len_a--;
	}
	else if (key == 1 && (t_info->max_len - t_info->len_b == 0))
	{
		ft_print_nbr(head, t_info);
		t_info->len_b--;
	}
	else
		while (++cnt <= t_info->max_width)
			ft_putchar_fd(' ', STD_OUT);
	if (key == 0)
		ft_putstr_fd(" | ", STD_OUT);
	else
		ft_putchar_fd('\n', STD_OUT);
}

static	void	ft_print_base(size_t width, int key)
{
	size_t	cnt;
	size_t	t_width;

	cnt = 0;
	t_width = (width * 2) + 3;
	if (key == 0)
		ft_putstr_fd("\n\n", STD_OUT);
	while (++cnt <= t_width)
		ft_putchar_fd('-', STD_OUT);
	ft_putchar_fd('\n', STD_OUT);
	if (key == 1)
	{
		cnt = 0;
		while (++cnt < width)
			ft_putchar_fd(' ', STD_OUT);
		ft_putchar_fd('A', STD_OUT);
		ft_putstr_fd(" | ", STD_OUT);
		while (--cnt > 0)
			ft_putchar_fd(' ', STD_OUT);
		ft_putstr_fd("B\n- ", STD_OUT);
	}
}

void	fn_list_print_workhorse(t_dlist **a, t_dlist **b, int *key)
{
	static t_print	t_info;

	if (*key & SHOW && !(*key & CHECKER))
		fn_clear_input_option(key);
	t_info.max_width = ft_list_max_min(a, b) + 1;
	t_info.len_a = ft_dlist_size(*a);
	t_info.len_b = ft_dlist_size(*b);
	t_info.max_len = t_info.len_b;
	if (t_info.len_a > t_info.len_b)
		t_info.max_len = t_info.len_a;
	ft_print_base(t_info.max_width, 0);
	while (t_info.max_len)
	{
		ft_print_frame(a, &t_info, 0);
		ft_print_frame(b, &t_info, 1);
		if (--t_info.max_len == 0)
			ft_print_base(t_info.max_width, 1);
	}
}
