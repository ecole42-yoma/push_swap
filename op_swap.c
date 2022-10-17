/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:16:53 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 16:39:23 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_swap(t_dlist **head)
{
	t_dlist	*temp;
	size_t	size;

	size = ft_dlist_size(*head);
	if (size >= 2)
	{
		temp = (*head)->next;
		(*head)->next = temp->next;
		temp->pre = NULLL;
		(*head)->pre = temp;
		if (size >= 3)
			temp->next->pre = *head;
		temp->next = *head;
		*head = temp;
		return (1);
	}
	return (0);
}

char	sa(t_stack *stack, char key)
{
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_swap(&stack->a);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	if (key & 16)
		return (A + SWAP);
	return (fn_op_net(stack, A + SWAP));
}

char	sb(t_stack *stack, char key)
{
	if (stack->show & INPUT)
	{
		fn_listprint(stack, key);
		ft_putstr_fd("before", STD_OUT);
	}
	ft_swap(&stack->b);
	if (key & SHOW)
	{
		stack->show |= 8;
		fn_listprint(stack, key);
	}
	if (key & 16)
		return (B + SWAP);
	return (fn_op_net(stack, B + SWAP));
}

char	ss(t_stack *stack)
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
	cnt |= sa(stack, stack->show);
	if (flag == 1)
		stack->show |= SHOW;
	cnt |= sb(stack, stack->show);
	if (flag == 1)
		stack->show ^= NOT_SHOW;
	return (fn_op_net(stack, cnt));
}
