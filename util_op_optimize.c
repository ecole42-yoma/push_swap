/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_op_optimize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:55:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/23 14:58:04 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	fn_save_init(char **save, t_stack *stack, int key)
{
	if (key == 0)
	{
		*save = (char *)malloc(sizeof(char) * 3);
		if (!(*save))
		{
			fn_free(&(stack->a), 0);
			exit(fn_free(&(stack->b), ERROR));
		}
	}
	(*save)[0] = '\0';
	(*save)[1] = '\0';
	(*save)[2] = '\0';
}

static void	fn_swap_save(char **save)
{
	char	temp;

	temp = (*save)[0];
	(*save)[0] = (*save)[1];
	(*save)[1] = temp;
}

static void	fn_op_sum(char **save)
{
	char	s1;
	char	s2;

	s1 = (*save)[0];
	s2 = (*save)[1];
	if (ft_abs(s1 - s2) == ft_abs(A - B))
	{
		if (!(s1 & PUSH) && !(s2 & PUSH))
			fn_is_printable(s1 | s2);
		fn_save_init(save, NULLL, 1);
	}
	else if (ft_abs(s1 - s2) == ft_abs(ROTATE - R_ROTATE))
		fn_save_init(save, NULLL, 1);
	else if (ft_abs(s1 - s2) == 0 && s1 & SWAP && s2 & SWAP)
		fn_save_init(save, NULLL, 1);
	else
	{
		fn_is_printable((*save)[0]);
		(*save)[0] = '\0';
		fn_swap_save(save);
	}
}

void	fn_op_optimize(t_stack *stack, char key)
{
	static char	*save;

	if (save == NULLL)
		fn_save_init(&save, stack, 0);
	if (key & (B + B))
	{
		fn_is_printable(save[0]);
		save[0] = '\0';
		free(save);
	}
	if (save[0] == '\0' && save[1] != '\0')
		fn_swap_save(&save);
	if (save[0] == '\0')
		save[0] = key;
	else if (save[1] == '\0')
		save[1] = key;
	if (save[0] != '\0' && save[1] != '\0')
		fn_op_sum(&save);
}
