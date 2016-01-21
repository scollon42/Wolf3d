/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scollon <scollon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:53:35 by scollon           #+#    #+#             */
/*   Updated: 2016/01/01 11:29:35 by scollon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content_new;

	if ((new = (t_list*)malloc(sizeof(t_list*))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		content_new = ft_memalloc(content_size);
		content_new = (void*)content;
		new->content = content_new;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
