/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_small_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:39:58 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 03:07:39 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_sort_a(t_stack *stack, int key)
{
	if (key & A)
		return (0);
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			sb(stack, stack->show);
			rrb(stack, stack->show);
			return (fn_push_size(stack, 3));
		}
		rb(stack, stack->show, NULLL);
		sb(stack, stack->show);
		pa(stack, stack->show, NULLL);
		rrb(stack, stack->show);
		sb(stack, stack->show);
		return (fn_push_size(stack, 2));
	}
	return (0);
}

int	fn_sort_b(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			rra(stack, stack->show);
			return (sa(stack, stack->show));
		}
		ra(stack, stack->show, NULLL);
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
		sb(stack, stack->show);
		pa(stack, stack->show, NULLL);
		sb(stack, stack->show);
		return (fn_push_size(stack, 2));
	}
	return (0);
}

static void	fn_three_init(t_three *info, t_stack *stack, int key)
{
	if (key & A)
	{
		info->v1 = stack->a->value;
		info->v2 = stack->a->next->value;
		info->v3 = stack->a->next->next->value;
	}
	else if (key & B)
	{
		info->v1 = stack->b->value;
		info->v2 = stack->b->next->value;
		info->v3 = stack->b->next->next->value;
	}
}

static void	fn_three_process(t_stack *stack, char key)
{
	t_three	t;

	fn_three_init(&t, stack, key);
	if (t.v1 < t.v2 && t.v1 < t.v3 && t.v2 < t.v3)
		fn_sort_a(stack, key);
	if (t.v1 < t.v2 && t.v1 < t.v3 && t.v2 > t.v3)
		fn_sort_b(stack, key);
	if (t.v1 > t.v2 && t.v1 < t.v3 && t.v2 < t.v3)
		fn_sort_c(stack, key);
	if (t.v1 < t.v2 && t.v1 > t.v3 && t.v2 > t.v3)
		fn_sort_d(stack, key);
	if (t.v1 > t.v2 && t.v1 > t.v3 && t.v2 < t.v3)
		fn_sort_e(stack, key);
	if (t.v1 > t.v2 && t.v1 > t.v3 && t.v2 > t.v3)
		fn_sort_f(stack, key);
}

int	fn_sort_small_case(t_stack *stack, size_t size, int key)
{
	if (size == 1 && key & B)
		return (pa(stack, stack->show, NULLL));
	if (size == 2)
	{
		if (key & A && stack->a->value > stack->a->next->value)
			return (sa(stack, stack->show));
		if (key & B)
		{
			if (stack->b->value < stack->b->next->value)
				sb(stack, stack->show);
			return (fn_push_size(stack, size));
		}
	}
	else if (size == 3)
		fn_three_process(stack, key);
	return (0);
}
