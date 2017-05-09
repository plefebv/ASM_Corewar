/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:59:54 by plefebvr          #+#    #+#             */
/*   Updated: 2017/05/09 14:01:31 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_power(int nbr, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (nbr * ft_power(nbr, power - 1));
}
