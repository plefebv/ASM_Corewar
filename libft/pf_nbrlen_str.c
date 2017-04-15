/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_nbrlen_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 22:27:19 by plefebvr          #+#    #+#             */
/*   Updated: 2016/10/01 18:53:04 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		pf_nbrlen_str(char *s)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (!(ft_isdigit(s[i])))
		i++;
	while (ft_isdigit(s[i + ret]))
		ret++;
	return (ret);
}
