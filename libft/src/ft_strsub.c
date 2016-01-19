/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 07:55:30 by scollon           #+#    #+#             */
/*   Updated: 2016/01/18 07:59:09 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	i = -1;
	if (s == NULL)
		return (NULL);
	if ((sub = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (++i != len)
		sub[i] = s[start++];
	sub[i] = 0;
	return (sub);
}
