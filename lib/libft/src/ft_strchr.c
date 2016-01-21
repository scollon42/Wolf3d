/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:30:24 by scollon           #+#    #+#             */
/*   Updated: 2016/01/18 07:56:39 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*ret;

	i = -1;
	ret = (unsigned char *)s;
	while (ret[++i] != 0)
	{
		if (ret[i] == c)
			return ((char *)&ret[i]);
	}
	if (ret[i] == c)
		return ((char *)&ret[i]);
	return (NULL);
}
