/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:33:05 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/22 12:03:35 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fn_is_printable(int key)
{
	if (key & SWAP && key & A && key & B)
		ft_putstr_fd("ss\n", STD_OUT);
	else if (key & SWAP && key & A)
		ft_putstr_fd("sa\n", STD_OUT);
	else if (key & SWAP && key & B)
		ft_putstr_fd("sb\n", STD_OUT);
	else if (key & PUSH && key & A && !(key & B))
		ft_putstr_fd("pa\n", STD_OUT);
	else if (key & PUSH && key & B && !(key & A))
		ft_putstr_fd("pb\n", STD_OUT);
	else if (key & ROTATE && key & A && key & B)
		ft_putstr_fd("rr\n", STD_OUT);
	else if (key & ROTATE && key & A)
		ft_putstr_fd("ra\n", STD_OUT);
	else if (key & ROTATE && key & B)
		ft_putstr_fd("rb\n", STD_OUT);
	else if (key & R_ROTATE && key & A && key & B)
		ft_putstr_fd("rrr\n", STD_OUT);
	else if (key & R_ROTATE && key & A)
		ft_putstr_fd("rra\n", STD_OUT);
	else if (key & R_ROTATE && key & B)
		ft_putstr_fd("rrb\n", STD_OUT);
}

int	fn_free(t_dlist **head, int key)
{
	if (*head != NULLL)
	{
		ft_dlist_del_all(head);
	}
	if (key & ERROR_OUT)
		return (ft_putstr_fd("Error\n", STD_ERR));
	return (0);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	fn_listprint(t_stack *stack, int key)
{
	t_dlist	*temp_a;
	t_dlist	*temp_b;

	if (key & SHOW)
	{
		temp_a = stack->a;
		temp_b = stack->b;
		fn_list_print_workhorse(&temp_a, &temp_b, &stack->show);
	}
}
