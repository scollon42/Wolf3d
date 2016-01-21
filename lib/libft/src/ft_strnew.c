/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:34:17 by scollon           #+#    #+#             */
/*   Updated: 2015/11/23 17:46:39 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * size + 1);
	if (new == NULL)
		return (NULL);
	while (i != size)
	{
		new[i] = 0;
		i++;
	}
	new[i] = 0;
	return (new);
}
