/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 10:02:07 by exam              #+#    #+#             */
/*   Updated: 2016/01/29 10:47:17 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_itoa(int nbr)
{
	int		len;
	int		abs;
	char	*ret;

	len = ft_nbrlen((long)nbr, &abs);
	if ((ret = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	ret[len] = '\0';
	abs == -1 ? ret[0] = '-' : 0;
	while (--len > 0)
	{
		ret[len] = ((nbr % 10) * abs) + '0';
		nbr /= 10;
	}
	if (abs == 1)
		ret[len] = (nbr % 10) + '0';
	return (ret);
}
