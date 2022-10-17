/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:46:11 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/22 11:45:24 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	fn_is_there_opt_check(char *str, char ***argv, int *cnt, int argc)
{
	char	*flag;

	flag = "-s";
	while (*flag && *str)
	{
		if (*str != *flag)
			return ;
		flag++;
		str++;
	}
	if (*flag)
		return ;
	if (*str == '\0')
	{
		if (argc != 2)
			*argv = &(*argv)[1];
		if (*cnt & NOT_SHOW)
			*cnt -= NOT_SHOW;
		*cnt |= SHOW;
	}
	return ;
}

static int	fn_init_check(t_stack *stack)
{
	stack->a = NULLL;
	stack->b = NULLL;
	stack->show = NOT_SHOW;
	return (0);
}

static void	fn_is_done(t_stack *stack)
{
	if (stack->b == NULLL)
	{
		if (!(fn_issort_dlist_asc(&(stack->a), ft_dlist_size(stack->a))))
			ft_putstr_fd("OK\n", STD_OUT);
		else
		{
			ft_putstr_fd("KO\n", STD_ERR);
		}
	}
	else
	{
		fn_free(&stack->b, SUCCESS);
		ft_putstr_fd("KO\n", STD_ERR);
		fn_free(&stack->b, SUCCESS);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	stack;

	if (argc <= 1)
		return (0);
	fn_init_check(&stack);
	fn_is_there_opt_check(argv[1], &argv, &stack.show, argc);
	if (stack.show & SHOW && argc == 2)
		exit(ft_putstr_fd("Error\n", STD_ERR));
	fn_argv_to_list(argc - (stack.show & SHOW), argv, &stack.a);
	if (stack.show & SHOW)
	{
		stack.show += 64;
		fn_listprint(&stack, stack.show);
		stack.show |= CHECKER;
		ft_putstr_fd("start\n\n-> ", STD_OUT);
	}
	fn_check_input(&stack);
	fn_is_done(&stack);
	return (fn_free(&stack.a, SUCCESS));
}
