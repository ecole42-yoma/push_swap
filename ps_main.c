/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:38:44 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/22 12:02:42 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	fn_init(t_stack *stack)
{
	stack->a = NULLL;
	stack->b = NULLL;
	stack->show = 0;
	return (0);
}

static void	fn_b_is_null(t_stack *stack)
{
	if (stack->show & SHOW)
	{
		if (!(fn_issort_dlist_asc(&(stack->a), ft_dlist_size(stack->a))) \
											&& stack->b == NULLL)
			ft_putstr_fd("\nOK\n", STD_OUT);
		else
			ft_putstr_fd("\nKO\n", STD_OUT);
	}
	if (stack->b != NULLL)
	{
		fn_free(&(stack->b), SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc <= 1)
		return (0);
	fn_init(&stack);
	fn_is_there_option(argv[1], &argv, &stack.show, argc);
	if (stack.show & SHOW && argc == 2)
		exit(ft_putstr_fd("Error\n", STD_ERR));
	fn_argv_to_list(argc - (stack.show & SHOW), argv, &stack.a);
	if (stack.show & SHOW)
	{
		stack.show |= 64;
		fn_listprint(&stack, stack.show);
		ft_putstr_fd("start\n", STD_OUT);
	}
	fn_sort_atob(&stack, ft_dlist_size(stack.a));
	if (stack.show & 64)
		fn_op_optimize(&stack, B + B);
	fn_b_is_null(&stack);
	return (fn_free(&stack.a, SUCCESS));
}
