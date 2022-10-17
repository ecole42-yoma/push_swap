/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_op_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:21:07 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/22 11:47:31 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	fn_op_net_exe(t_stack *stack, int key)
{
	if (key & SWAP && key & A && key & B)
		ss(stack);
	else if (key & SWAP && key & A)
		sa(stack, stack->show);
	else if (key & SWAP && key & B)
		sb(stack, stack->show);
	else if (key & PUSH && key & A)
		pa(stack, stack->show, NULLL);
	else if (key & PUSH && key & B)
		pb(stack, stack->show, NULLL);
	else if (key & ROTATE && key & A && key & B)
		rr(stack);
	else if (key & ROTATE && key & A)
		ra(stack, stack->show, NULLL);
	else if (key & ROTATE && key & B)
		rb(stack, stack->show, NULLL);
	else if (key & R_ROTATE && key & A && key & B)
		rrr(stack);
	else if (key & R_ROTATE && key & A)
		rra(stack, stack->show);
	else if (key & R_ROTATE && key & B)
		rrb(stack, stack->show);
}

int	fn_op_net(t_stack *stack, char key)
{
	if (!(stack->show & NOT_SHOW))
	{
		if (stack->show & SHOW)
		{
			fn_is_printable(key);
		}
		else if (stack->show & 64)
		{
			fn_op_optimize(stack, key);
		}
	}
	if (stack->show & SHOW && stack->show & CHECKER)
		ft_putstr_fd("\n-> ", STD_OUT);
	return (0);
}

static int	is_operation(char *str)
{
	if (ft_strcmp(str, "ss\n") == 0)
		return (SWAP + A + B);
	else if (ft_strcmp(str, "sa\n") == 0)
		return (SWAP + A);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (SWAP + B);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (PUSH + A);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (PUSH + B);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (ROTATE + A + B);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ROTATE + A);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (ROTATE + B);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (R_ROTATE + A + B);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (R_ROTATE + A);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (R_ROTATE + B);
	return (0);
}

static void	fn_before_print(t_stack *stack)
{
	system("clear");
	fn_listprint(stack, SHOW);
	ft_putstr_fd("before\n", STD_OUT);
}

void	fn_check_input(t_stack *stack)
{
	char	*buf;
	int		opt;

	buf = get_next_line(STD_IN);
	opt = 0;
	while (buf != 0)
	{
		opt = is_operation(buf);
		free(buf);
		if (opt)
		{
			if (stack->show & SHOW)
				fn_before_print(stack);
			fn_op_net_exe(stack, opt);
		}
		else
		{
			fn_free(&(stack->a), SUCCESS);
			exit (fn_free(&(stack->b), ERROR));
		}
		buf = get_next_line(STD_IN);
	}
}
