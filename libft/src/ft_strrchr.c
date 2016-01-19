/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:01:46 by scollon           #+#    #+#             */
/*   Updated: 2015/11/26 12:58:54 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	*ret;

	i = ft_strlen(s);
	ret = (char *)s;
	if (c == ret[i])
		return (&ret[i]);
	while (i >= 0)
	{
		if (ret[i] == c)
			return (&ret[i]);
		i--;
	}
	return (NULL);
}
