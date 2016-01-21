/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 12:42:49 by scollon           #+#    #+#             */
/*   Updated: 2015/11/25 09:27:45 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	char			*b1;

	i = 0;
	b1 = (char*)b;
	while (i != len)
	{
		b1[i] = c;
		i++;
	}
	return (b1);
}
