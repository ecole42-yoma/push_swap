/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_small_sort_proc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:03:45 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 00:45:50 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_sort_c(t_stack *stack, int key)
{
	if (key & A)
	{
		return (sa(stack, stack->show));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			rrb(stack, stack->show);
			return (fn_push_size(stack, 3));
		}
		rb(stack, stack->show, NULLL);
		sb(stack, stack->show);
		pa(stack, stack->show, NULLL);
		rrb(stack, stack->show);
		return (fn_push_size(stack, 2));
	}
	return (0);
}

int	fn_sort_d(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			return (rra(stack, stack->show));
		}
		ra(stack, stack->show, NULLL);
		sa(stack, stack->show);
		rra(stack, stack->show);
		return (sa(stack, stack->show));
	}
	else if (key & B)
	{
		sb(stack, stack->show);
		return (fn_push_size(stack, 3));
	}
	return (0);
}

int	fn_sort_e(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
			return (ra(stack, stack->show, NULLL));
		sa(stack, stack->show);
		ra(stack, stack->show, NULLL);
		sa(stack, stack->show);
		return (rra(stack, stack->show));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			pa(stack, stack->show, NULLL);
			sb(stack, stack->show);
			return (fn_push_size(stack, 2));
		}
		rb(stack, stack->show, NULLL);
		sb(stack, stack->show);
		rrb(stack, stack->show);
		return (fn_push_size(stack, 3));
	}
	return (0);
}

int	fn_sort_f(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			sa(stack, stack->show);
			return (rra(stack, stack->show));
		}
		ra(stack, stack->show, NULLL);
		sa(stack, stack->show);
		pb(stack, stack->show, NULLL);
		rra(stack, stack->show);
		sa(stack, stack->show);
		return (pa(stack, stack->show, NULLL));
	}
	else if (key & B)
	{
		return (fn_push_size(stack, 3));
	}
	return (0);
}
