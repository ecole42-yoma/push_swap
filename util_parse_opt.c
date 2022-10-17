/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:47:03 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/23 12:58:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	fn_is_argc_end(char **argv, t_parse *parse)
{
	if (*argv[parse->argc_idx] == '\0')
	{
		if (parse->is_find == 0)
		{
			parse->key = ERROR;
			return (0);
		}
		parse->argc_idx++;
		parse->is_find = 0;
		return (1);
	}
	return (0);
}

void	fn_mv_atoi_init(t_atoi *info)
{
	info->sum = 0;
	info->sign = 1;
	info->cnt = 0;
}
