/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:02:07 by exam              #+#    #+#             */
/*   Updated: 2016/01/14 14:18:22 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa(int nbr)
{
	int		i;
	int		len;
	int		abs;
	char	*ret;

	abs = 1;
	len = ft_nbrlen((long)nbr, &abs);
	i = len - 1;
	if((ret = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ret[len] = '\0';
	if (abs == -1)
		ret[0] = '-';
	while (i > 0)
	{
		ret[i] = ((nbr % 10) * abs) + '0';
		nbr /= 10;
		i--;
	}
	if (abs == 1)
		ret[i] = (nbr % 10) + '0';
	return (ret);
}
