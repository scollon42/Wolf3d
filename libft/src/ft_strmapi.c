/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:54:28 by scollon           #+#    #+#             */
/*   Updated: 2015/11/26 10:02:41 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		size;
	int			i;
	char		*new;

	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s) + 1;
	i = 0;
	if ((new = (char *)malloc(sizeof(*new) * size)) == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
