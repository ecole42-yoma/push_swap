/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:46:06 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 13:18:24 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_push(t_dlist **from, t_dlist **to)
{
	t_dlist	*temp;

	if (*from)
	{
		temp = (*from)->next;
		(*from)->pre = NULLL;
		if (temp)
			temp->pre = NULLL;
		if (*to == NULLL)
			(*from)->next = NULLL;
		else
		{
			(*from)->next = *to;
			(*to)->pre = *from;
		}
		*to = *from;
		*from = temp;
		return (1);
	}
	return (0);
}

char	pa(t_stack *stack, char key, t_pivot *pvt)
{
	if (pvt != NULLL)
		pvt->pa++;
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_push(&stack->b, &stack->a);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	return (fn_op_net(stack, A + PUSH));
}

char	pb(t_stack *stack, char key, t_pivot *pvt)
{
	if (pvt != NULLL)
		pvt->pb++;
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_push(&stack->a, &stack->b);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	return (fn_op_net(stack, B + PUSH));
}
