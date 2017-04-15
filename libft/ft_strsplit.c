/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:58:08 by plefebvr          #+#    #+#             */
/*   Updated: 2016/11/23 16:10:50 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_strw(const char *str, char c)
{
	int		i;
	char	*strnew;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	strnew = ft_strnew(i);
	i = 0;
	while (str[i] != c && str[i] != '\0')
	{
		strnew[i] = str[i];
		i++;
	}
	return (strnew);
}

static int		l_wordcount(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c)
		{
			j++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**strback;
	int		word;

	i = 0;
	word = 0;
	if ((strback = (char **)malloc(sizeof(char *) * l_wordcount(str, c) + 1)))
	{
		while (str[i] != '\0')
		{
			while (str[i] == c)
				i++;
			if (str[i] != '\0' && str[i] != c)
				strback[word++] = ft_strw(&str[i], c);
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		strback[word] = NULL;
		return (strback);
	}
	else
		return (NULL);
}
