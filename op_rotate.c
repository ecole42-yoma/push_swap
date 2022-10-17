/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 20:46:08 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 16:39:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_rotate(t_dlist **head)
{
	t_dlist	*temp;
	t_dlist	*last;
	size_t	size;

	size = ft_dlist_size(*head);
	if (size >= 2)
	{
		temp = (*head)->next;
		temp->pre = NULLL;
		last = ft_dlist_last(*head);
		(*head)->pre = last;
		(*head)->next = NULLL;
		last->next = *head;
		*head = temp;
		return (1);
	}
	return (0);
}

char	ra(t_stack *stack, char key, t_pivot *pvt)
{
	if (pvt != NULLL)
		pvt->ra++;
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_rotate(&stack->a);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	if (key & 16)
		return (A + ROTATE);
	return (fn_op_net(stack, A + ROTATE));
}

char	rb(t_stack *stack, char key, t_pivot *pvt)
{
	if (pvt != NULLL)
		pvt->rb++;
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_rotate(&stack->b);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	if (key & 16)
		return (B + ROTATE);
	return (fn_op_net(stack, B + ROTATE));
}

char	rr(t_stack *stack)
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
	cnt |= ra(stack, stack->show, NULLL);
	if (flag == 1)
		stack->show |= SHOW;
	cnt |= rb(stack, stack->show, NULLL);
	if (flag == 1)
		stack->show ^= NOT_SHOW;
	return (fn_op_net(stack, cnt));
}
