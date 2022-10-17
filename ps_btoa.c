/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:41:19 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 03:09:56 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_rrb_btoa(t_stack *stack, size_t size)
{
	t_pivot	pvt;

	if (size <= 3)
		return (fn_sort_small_case_rra(stack, size, B));
	fn_init_pivot(&pvt);
	ft_dlist_find_pivot_tail(stack->b, size, &pvt);
	while (pvt.cnt++ < size)
	{
		rrb(stack, stack->show);
		if (stack->b->value > pvt.pivot_bot)
		{
			pa(stack, stack->show, &pvt);
			if (stack->a->value <= pvt.pivot_top)
				ra(stack, stack->show, &pvt);
		}
	}
	fn_sort_atob(stack, pvt.pa - pvt.ra);
	fn_rra_atob(stack, pvt.ra);
	return (fn_sort_btoa(stack, size - pvt.pa));
}

int	fn_sort_btoa(t_stack *stack, size_t size)
{
	t_pivot	pvt;

	if (fn_issort_dlist_dsc(&(stack->b), size) == SUCCESS)
		return (fn_push_size(stack, size));
	if (size <= 3)
		return (fn_sort_small_case(stack, size, B));
	fn_init_pivot(&pvt);
	ft_dlist_find_pivot_head(stack->b, size, &pvt);
	while (pvt.cnt++ < size)
	{
		if (stack->b->value <= pvt.pivot_bot)
			rb(stack, stack->show, &pvt);
		else
		{
			pa(stack, stack->show, &pvt);
			if (stack->a->value < pvt.pivot_top)
				ra(stack, stack->show, &pvt);
		}
	}
	fn_sort_atob(stack, pvt.pa - pvt.ra);
	fn_rra_atob(stack, pvt.ra);
	if (ft_dlist_size(stack->b) == pvt.rb)
		return (fn_sort_btoa(stack, pvt.rb));
	else
		return (fn_rrb_btoa(stack, pvt.rb));
}
