/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:22:09 by plefebvr          #+#    #+#             */
/*   Updated: 2016/03/21 20:44:02 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	void	*contenttemp;
	t_list	*newl;

	newl = (t_list *)malloc(sizeof(t_list));
	if (!newl)
		return (NULL);
	if (content == NULL)
	{
		newl->content = NULL;
		newl->content_size = 0;
		newl->next = NULL;
		return (newl);
	}
	if ((contenttemp = (void *)malloc(content_size)))
	{
		newl->content = ft_memcpy(contenttemp, (void *)content, content_size);
		newl->content_size = content_size;
		newl->next = NULL;
		return (newl);
	}
	else
		return (NULL);
}
