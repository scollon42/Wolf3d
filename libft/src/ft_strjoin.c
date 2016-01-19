/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 07:55:55 by scollon           #+#    #+#             */
/*   Updated: 2016/01/18 07:57:24 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	size;
	char	*join;

	i = 0;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if ((join = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while (s1[++j] != 0)
		join[i++] = s1[j];
	j = -1;
	while (s2[++j] != 0)
		join[i++] = s2[j];
	join[i] = 0;
	return (join);
}
