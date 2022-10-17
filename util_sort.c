/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 14:26:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 01:52:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_push_size(t_stack *stack, size_t size)
{
	while (size--)
		pa(stack, stack->show, NULLL);
	return (0);
}

int	fn_r_rotate_size(t_stack *stack, size_t size, int key)
{
	if (key & A)
	{
		while (size--)
			rra(stack, stack->show);
	}
	if (key & B)
	{
		while (size--)
		{
			rrb(stack, stack->show);
		}
	}
	return (0);
}

int	fn_issort_dlist_asc(t_dlist **head, size_t size)
{
	t_dlist	*pos;
	t_dlist	*mov;
	size_t	pos_cnt;
	size_t	mov_cnt;

	pos = *head;
	pos_cnt = 0;
	while (pos && pos_cnt < size)
	{
		mov_cnt = 0;
		mov = pos->next;
		while (mov && mov_cnt++ < size)
		{
			if (pos->value > mov->value)
				return (ERROR);
			mov = mov->next;
		}
		pos_cnt++;
		pos = pos->next;
	}
	return (SUCCESS);
}

int	fn_issort_dlist_dsc(t_dlist **head, size_t size)
{
	t_dlist	*pos;
	t_dlist	*mov;
	size_t	pos_cnt;
	size_t	mov_cnt;

	pos = *head;
	pos_cnt = 0;
	while (pos && pos_cnt < size)
	{
		mov_cnt = 0;
		mov = pos->next;
		while (mov && mov_cnt++ < size)
		{
			if (pos->value < mov->value)
				return (ERROR);
			mov = mov->next;
		}
		pos_cnt++;
		pos = pos->next;
	}
	return (SUCCESS);
}
