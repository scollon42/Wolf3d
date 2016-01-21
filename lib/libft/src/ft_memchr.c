/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:51:51 by scollon           #+#    #+#             */
/*   Updated: 2015/11/26 13:24:04 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	ct;

	i = 0;
	s1 = (unsigned char *)s;
	ct = (unsigned char)c;
	if (s == NULL)
		return (NULL);
	while (i != n)
	{
		if (s1[i] == ct)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}
