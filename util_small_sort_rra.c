/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_small_sort_rra.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:17:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 03:10:37 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_sort_a_rra(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			return (ra(stack, stack->show, NULLL));
		}
		fn_r_rotate_size(stack, 2, A);
		sa(stack, stack->show);
		rra(stack, stack->show);
		return (sa(stack, stack->show));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			sb(stack, stack->show);
			return (fn_push_size(stack, 3));
		}
		fn_r_rotate_size(stack, 2, B);
		pa(stack, stack->show, NULLL);
		rrb(stack, stack->show);
		return (fn_push_size(stack, 2));
	}
	return (0);
}

int	fn_sort_b_rra(t_stack *stack, int key)
{
	if (key & A)
	{
		if (ft_dlist_size(stack->a) == 3)
		{
			fn_r_rotate_size(stack, 3, A);
			return (sa(stack, stack->show));
		}
		rra(stack, stack->show);
		pb(stack, stack->show, NULLL);
		fn_r_rotate_size(stack, 2, A);
		sa(stack, stack->show);
		return (pa(stack, stack->show, NULLL));
	}
	else if (key & B)
	{
		if (ft_dlist_size(stack->b) == 3)
		{
			return (fn_push_size(stack, 3));
		}
		fn_r_rotate_size(stack, 3, B);
		return (fn_push_size(stack, 3));
	}
	return (0);
}

static void	fn_three_init_rra(t_three *info, t_stack *stack, int key)
{
	t_dlist	*temp;

	if (key & A)
	{
		temp = ft_dlist_last(stack->a);
		info->v1 = temp->value;
		info->v2 = temp->pre->pre->value;
		info->v3 = temp->pre->value;
	}
	else if (key & B)
	{
		temp = ft_dlist_last(stack->b);
		info->v1 = temp->value;
		info->v2 = temp->pre->pre->value;
		info->v3 = temp->pre->value;
	}
}

static int	fn_three_process_rra(t_stack *stack, char key)
{
	t_three	t;

	fn_three_init_rra(&t, stack, key);
	if (t.v1 < t.v2 && t.v1 < t.v3 && t.v2 < t.v3)
		fn_sort_a_rra(stack, key);
	else if (t.v1 < t.v2 && t.v1 < t.v3 && t.v2 > t.v3)
		fn_sort_b_rra(stack, key);
	else if (t.v1 > t.v2 && t.v1 < t.v3 && t.v2 < t.v3)
		fn_sort_c_rra(stack, key);
	else if (t.v1 < t.v2 && t.v1 > t.v3 && t.v2 > t.v3)
		fn_sort_d_rra(stack, key);
	else if (t.v1 > t.v2 && t.v1 > t.v3 && t.v2 < t.v3)
		fn_sort_e_rra(stack, key);
	else if (t.v1 > t.v2 && t.v1 > t.v3 && t.v2 > t.v3)
		fn_sort_f_rra(stack, key);
	return (0);
}

int	fn_sort_small_case_rra(t_stack *stack, size_t size, int key)
{
	if ((size == 2 || size == 1) && key & A)
		fn_r_rotate_size(stack, size, key);
	else if ((size == 2 || size == 1) && key & B)
		fn_r_rotate_size(stack, 1, key);
	if (size == 2)
	{
		if (key & A && stack->a->value > stack->a->next->value)
			return (sa(stack, stack->show));
		if (key & B)
		{
			if (stack->b->value > ft_dlist_last(stack->b)->value)
			{
				pa(stack, stack->show, NULLL);
				rrb(stack, stack->show);
				return (fn_push_size(stack, size - 1));
			}
			rrb(stack, stack->show);
		}
	}
	else if (size == 3)
		return (fn_three_process_rra(stack, key));
	if (key & B)
		return (fn_push_size(stack, size));
	return (0);
}
