/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:54:56 by scollon           #+#    #+#             */
/*   Updated: 2015/11/30 08:16:44 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_cpy;
	unsigned char	*s2_cpy;
	unsigned int	i;

	s1_cpy = (unsigned char *)s1;
	s2_cpy = (unsigned char *)s2;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (i != n)
	{
		if (s1_cpy[i] != s2_cpy[i] || i >= n - 1)
			return ((unsigned char)s1_cpy[i] - (unsigned char)s2_cpy[i]);
		i++;
	}
	return (0);
}
