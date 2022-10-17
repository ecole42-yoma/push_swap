/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:27:56 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/22 00:53:50 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_rra_atob(t_stack *stack, size_t cycle)
{
	t_pivot	pvt;

	if (cycle <= 3)
		return (fn_sort_small_case_rra(stack, cycle, A));
	fn_init_pivot(&pvt);
	ft_dlist_find_pivot_tail(stack->a, cycle, &pvt);
	while (pvt.cnt++ < cycle)
	{
		rra(stack, stack->show);
		if (stack->a->value <= pvt.pivot_top)
		{
			pb(stack, stack->show, &pvt);
			if (stack->b->value > pvt.pivot_bot)
				rb(stack, stack->show, &pvt);
		}
	}
	fn_sort_atob(stack, cycle - pvt.pb);
	fn_rrb_btoa(stack, pvt.rb);
	return (fn_sort_btoa(stack, pvt.pb - pvt.rb));
}

static void	fn_is_rb_effi(t_stack *stack, t_pivot *pvt)
{
	if (stack->b->value <= pvt->pivot_bot)
		pvt->ok = 1;
	if (stack->b->value > pvt->pivot_bot)
	{
		if (pvt->ok == 1 || (pvt->pb < ft_dlist_size(stack->b)))
			rb(stack, stack->show, pvt);
		else
			pvt->rb++;
	}
}

int	fn_sort_atob(t_stack *stack, size_t cycle)
{
	t_pivot	pvt;

	if (fn_issort_dlist_asc(&(stack->a), cycle) == SUCCESS)
		return (0);
	if (cycle <= 3)
		return (fn_sort_small_case(stack, cycle, A));
	fn_init_pivot(&pvt);
	ft_dlist_find_pivot_head(stack->a, cycle, &pvt);
	while (pvt.cnt++ < cycle)
	{
		if (stack->a->value > pvt.pivot_top)
			ra(stack, stack->show, &pvt);
		else
		{
			pb(stack, stack->show, &pvt);
			fn_is_rb_effi(stack, &pvt);
		}
	}
	if (ft_dlist_size(stack->a) == pvt.ra)
		fn_sort_atob(stack, pvt.ra);
	else
		fn_rra_atob(stack, pvt.ra);
	fn_rrb_btoa(stack, pvt.rb);
	return (fn_sort_btoa(stack, pvt.pb - pvt.rb));
}
