/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 06:22:26 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/06 06:24:44 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrealloc(char *str, size_t size)
{
	char	*ret;

	ret = ft_strnew(size);
	ft_memcpy(ret, str, ft_strlen(str));
	ft_memdel((void **)&str);
	return (ret);
}
