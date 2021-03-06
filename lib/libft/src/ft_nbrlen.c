/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:12:44 by scollon           #+#    #+#             */
/*   Updated: 2016/01/29 14:28:43 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long n, int *abs)
{
	int	len;

	len = 0;
	*abs = 1;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		*abs = -1;
		len += 1;
	}
	while (n > 0)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}
