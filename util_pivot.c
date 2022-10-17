/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:03:23 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/20 23:41:27 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ft_dlist_find_pivot_a(t_dlist_pivot *pivot, size_t n, t_pivot *i)
{
	if ((n == 5 || n == 4) && pivot->more == 3)
	{
		i->pivot_top = pivot->pos->value;
		i->pivot_bot = pivot->pos->value;
		pivot->cnt = 2;
	}
	else if (n > 5)
	{
		if (pivot->more == (n / 3))
		{
			i->pivot_top = pivot->pos->value;
			pivot->cnt += 1;
			return ;
		}
		if (pivot->more == (n - (n / 3)))
		{
			i->pivot_bot = pivot->pos->value;
			pivot->cnt += 1;
		}
	}
}

static void	ft_pivot_util(t_dlist *lst, t_dlist_pivot *pivot, int key)
{
	if (key & 1)
	{
		pivot->cnt = 0;
		pivot->i = 0;
	}
	if (key & 2)
		pivot->pos = lst;
	if (key & 4)
		pivot->pos = ft_dlist_last(lst);
	if (key & 8)
	{
		pivot->more = 0;
		pivot->j = 0;
	}
	if (key & 16)
		pivot->mov = lst;
	if (key & 32)
		pivot->mov = ft_dlist_last(lst);
}

void	ft_dlist_find_pivot_tail(t_dlist *lst, size_t cycle, t_pivot *info)
{
	t_dlist_pivot	pivot;

	ft_pivot_util(lst, &pivot, 1 + 4);
	while (pivot.i++ < cycle && pivot.pos)
	{
		ft_pivot_util(lst, &pivot, 8 + 32);
		while (pivot.mov && pivot.j++ < cycle)
		{
			if (pivot.pos->value < pivot.mov->value)
				pivot.more++;
			pivot.mov = pivot.mov->pre;
		}
		ft_dlist_find_pivot_a(&pivot, cycle, info);
		if (pivot.cnt == 2)
		{
			return ;
		}
		pivot.pos = pivot.pos->pre;
	}
}

void	ft_dlist_find_pivot_head(t_dlist *lst, size_t cycle, t_pivot *info)
{
	t_dlist_pivot	pivot;

	ft_pivot_util(lst, &pivot, 1 + 2);
	while (pivot.i < cycle && pivot.pos)
	{
		ft_pivot_util(lst, &pivot, 8 + 16);
		while (pivot.mov && pivot.j < cycle)
		{
			if (pivot.pos->value < pivot.mov->value)
				pivot.more++;
			pivot.mov = pivot.mov->next;
			pivot.j++;
		}
		ft_dlist_find_pivot_a(&pivot, cycle, info);
		if (pivot.cnt == 2)
		{
			return ;
		}
		pivot.pos = pivot.pos->next;
		pivot.i++;
	}
}

void	fn_init_pivot(t_pivot *pivot)
{
	pivot->cnt = 0;
	pivot->pa = 0;
	pivot->pb = 0;
	pivot->ra = 0;
	pivot->rb = 0;
	pivot->more = 0;
}
