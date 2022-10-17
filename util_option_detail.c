/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_option_detail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:24:52 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/20 21:36:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fn_is_other_option(char **str, int *cnt)
{
	if (**str == 'c')
	{
		*cnt += CLEAR;
		(*str)++;
	}
	if (**str == 'i')
	{
		*cnt += INPUT;
		if (*cnt & CLEAR)
			*cnt -= CLEAR;
		(*str)++;
	}
}

int	fn_clear_input_option(int *key)
{
	char	buf;

	if (*key & CLEAR)
	{
		usleep(500000);
		return (system("clear"));
	}
	if (*key & 8)
	{
		*key -= 8;
		return (0);
	}
	if (*key & INPUT && !(*key & 64))
	{
		while (read(0, &buf, 1) != -1)
		{
			if (buf == '\n')
				break ;
		}
	}
	if (*key & 64)
		*key -= 64;
	system("clear");
	return (0);
}
