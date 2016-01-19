/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 08:58:25 by scollon           #+#    #+#             */
/*   Updated: 2016/01/06 12:32:40 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str, int len)
{
	int	start;
	int end;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		ft_swap(&str[start], &str[end]);
		start++;
		end--;
	}
}
