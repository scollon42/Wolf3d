/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:42:30 by scollon           #+#    #+#             */
/*   Updated: 2015/11/26 10:02:18 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t			size;
	unsigned int	i;
	char			*new;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s) + 1;
	i = 0;
	if ((new = (char *)malloc(sizeof(*new) * size)) == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
