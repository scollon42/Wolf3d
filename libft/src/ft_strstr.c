/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:04:32 by scollon           #+#    #+#             */
/*   Updated: 2015/11/28 09:02:11 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	if (s2[j] == 0)
		return ((char*)s1);
	while (s1[i] != 0)
	{
		if (s1[i] == s2[j])
		{
			while (s2[j] != 0)
			{
				if (s1[i + j] != s2[j])
					break ;
				j++;
			}
			if (s2[j] == 0)
				return ((char *)&s1[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
