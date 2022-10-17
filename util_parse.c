/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:35:54 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/23 13:04:04 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	fn_is_there_option(char *str, char ***argv, int *cnt, int argc)
{
	char	*flag;

	flag = "-s";
	*cnt = 0;
	while (*flag && *str)
	{
		if (*str != *flag)
		{
			*cnt = 64;
			return ;
		}
		flag++;
		str++;
	}
	if (*flag)
		return ;
	fn_is_other_option(&str, cnt);
	if (*str == '\0')
	{
		if (argc != 2)
			*argv = &(*argv)[1];
		*cnt += SHOW;
	}
	return ;
}

static void	ft_atoi_util(char **str, int *key, long long *sign, int pos)
{
	if (pos == 0)
	{
		if (**str == '-' || **str == '+')
		{
			if (**str == '-')
				*sign = -1;
			(*str)++;
			if (**str == '\0' || ft_isspace(**str) || !ft_isdigit(**str))
				*key = ERROR;
		}
	}
	else if (pos == 1)
	{
		if ((*sign) > MAX_INT || (*sign) < MIN_INT)
			*key = ERROR;
	}
}

static ssize_t	ft_mv_atoi(char **str, int *key)
{
	t_atoi	info;

	fn_mv_atoi_init(&info);
	while (ft_isspace(**str))
		(*str)++;
	ft_atoi_util(str, key, &info.sign, 0);
	while (**str <= 127 && **str >= 33)
	{
		if (ft_isdigit(**str))
			info.sum = (info.sum * 10) + ((**str) - '0');
		else
			*key = ERROR;
		(*str)++;
		info.cnt++;
		if (info.cnt > 1 && info.sum == 0)
			*key = ERROR;
	}
	if (info.cnt == 0 && info.sum == 0 && *key != ERROR)
		*key = JUMP;
	info.sum *= info.sign;
	ft_atoi_util(str, key, &info.sum, 1);
	return ((ssize_t)(info.sum));
}

static int	ft_isdup_value(t_dlist **a, int is_dup)
{
	if (ft_dlist_find(*a, is_dup) == NULLL)
		return (SUCCESS);
	return (ERROR);
}

void	fn_argv_to_list(int argc, char **argv, t_dlist **stack)
{
	t_parse	parse;

	parse.argc_idx = 1;
	parse.is_find = 0;
	while (parse.argc_idx < argc)
	{
		parse.key = SUCCESS;
		if (fn_is_argc_end(argv, &parse))
			continue ;
		parse.temp = ft_mv_atoi(&argv[parse.argc_idx], &parse.key);
		if (parse.key == JUMP)
			continue ;
		if (parse.key == ERROR || ft_isdup_value(stack, parse.temp) == ERROR)
			exit(fn_free(stack, ERROR_OUT));
		parse.list_temp = ft_dlist_new(parse.temp);
		if (parse.list_temp == NULL)
			exit(fn_free(stack, ERROR_OUT));
		parse.is_find = 1;
		if (*stack == NULLL)
			*stack = parse.list_temp;
		else
			ft_dlist_add_back(stack, parse.list_temp);
	}
}
