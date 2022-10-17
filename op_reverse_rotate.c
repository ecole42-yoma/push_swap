/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:46:09 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 16:38:41 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_reverse_rotate(t_dlist **head)
{
	t_dlist	*last;

	if (ft_dlist_size(*head) >= 2)
	{
		last = ft_dlist_last(*head);
		last->pre->next = NULLL;
		last->pre = NULLL;
		last->next = *head;
		(*head)->pre = last;
		*head = last;
		return (1);
	}
	return (0);
}

char	rra(t_stack *stack, char key)
{
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_reverse_rotate(&stack->a);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	if (key & 16)
		return (A + R_ROTATE);
	return (fn_op_net(stack, A + R_ROTATE));
}

char	rrb(t_stack *stack, char key)
{
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_reverse_rotate(&stack->b);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	if (key & 16)
		return (B + R_ROTATE);
	return (fn_op_net(stack, B + R_ROTATE));
}

char	rrr(t_stack *stack)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	if (stack->show & SHOW)
	{
		stack->show ^= SHOW;
		stack->show |= NOT_SHOW;
		flag = 1;
	}
	cnt |= rra(stack, stack->show);
	if (flag == 1)
		stack->show |= SHOW;
	cnt |= rrb(stack, stack->show);
	if (flag == 1)
		stack->show ^= NOT_SHOW;
	return (fn_op_net(stack, cnt));
}
