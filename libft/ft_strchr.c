/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 00:04:13 by yongmkim          #+#    #+#             */
/*   Updated: 2022/03/21 16:03:59 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	if (!s)
		return (NULL);
	temp = (char *)s;
	while (1)
	{
		if (*temp == (char)c)
			return (temp);
		if (*temp == '\0')
			return (NULL);
		temp++;
	}
}
