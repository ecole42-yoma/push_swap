/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_small_sort_rra_proc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:59:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 02:05:27 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_sort_c_rra(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			return (sa(stack, stack->show));
		}
		fn_r_rotate_size(stack, 2, A);
		sa(stack, stack->show);
		return (rra(stack, stack->show));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			rb(stack, stack->show, NULLL);
			return (fn_push_size(stack, 3));
		}
		fn_r_rotate_size(stack, 2, B);
		fn_push_size(stack, 2);
		rrb(stack, stack->show);
		return (fn_push_size(stack, 1));
	}
	return (0);
}

int	fn_sort_d_rra(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
			return (ra(stack, stack->show, NULLL));
		fn_r_rotate_size(stack, 2, A);
		pb(stack, stack->show, NULLL);
		rra(stack, stack->show);
		sa(stack, stack->show);
		return (pa(stack, stack->show, NULLL));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			pa(stack, stack->show, NULLL);
			sb(stack, stack->show);
			return (fn_push_size(stack, 2));
		}
		fn_r_rotate_size(stack, 3, B);
		pa(stack, stack->show, NULLL);
		sb(stack, stack->show);
		return (fn_push_size(stack, 2));
	}
	return (0);
}

int	fn_sort_e_rra(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			return (0);
		}
		fn_r_rotate_size(stack, 2, A);
		return (rra(stack, stack->show));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			sb(stack, stack->show);
			rrb(stack, stack->show);
			return (fn_push_size(stack, 3));
		}
		rrb(stack, stack->show);
		pa(stack, stack->show, NULLL);
		rrb(stack, stack->show);
		pa(stack, stack->show, NULLL);
		rrb(stack, stack->show);
		return (fn_push_size(stack, 1));
	}
	return (0);
}

int	fn_sort_f_rra(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			return (sa(stack, stack->show));
		}
		fn_r_rotate_size(stack, 3, A);
		return (sa(stack, stack->show));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			rrb(stack, stack->show);
			return (fn_push_size(stack, 3));
		}
		rrb(stack, stack->show);
		pa(stack, stack->show, NULLL);
		fn_r_rotate_size(stack, 2, B);
		return (fn_push_size(stack, 2));
	}
	return (0);
}
