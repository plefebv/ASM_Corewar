/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 16:09:04 by plefebvr          #+#    #+#             */
/*   Updated: 2016/09/30 18:12:40 by plefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static int		parse_read(char **tab, char **buf, char **line, char *temp2)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *line;
	if (ft_checkchar(buf[0], '\n') == 1)
	{
		line[0] = ft_strjoin(line[0], buf[0]);
		ft_memdel((void **)&temp);
		return (2);
	}
	while (buf[0][i] != '\n' && buf[0][i])
		i++;
	temp2 = ft_strndup(buf[0], i);
	*line = ft_strjoin(*line, temp2);
	ft_memdel((void **)&temp2);
	ft_memdel((void **)&temp);
	temp = tab[0];
	tab[0] = ft_strsub(buf[0], i + 1, ft_strlen(buf[0]) - i);
	ft_memdel((void **)&temp);
	return (1);
}

static int		parse_tab(char **tab, char **line, char *temp)
{
	int		i;
	char	*temp2;

	i = 0;
	temp2 = NULL;
	temp = *line;
	while (tab[0][i] != '\n' && tab[0][i])
		i++;
	temp2 = ft_strndup(tab[0], i);
	*line = ft_strjoin(*line, temp2);
	ft_memdel((void **)&temp2);
	ft_memdel((void **)&temp);
	temp = tab[0];
	tab[0] = ft_strsub(tab[0], i + 1, ft_strlen(tab[0]) - i - 1);
	ft_memdel((void **)&temp);
	return (1);
}

static int		check_tab(char **tab, char **line, char **buf)
{
	int		i;
	char	*temp;

	temp = *line;
	i = 0;
	if (tab[0] && ft_checkchar(tab[0], '\n') == 1)
	{
		*line = ft_strjoin(*line, tab[0]);
		ft_memdel((void **)&temp);
		ft_memdel((void **)&tab[0]);
		return (2);
	}
	else if (tab[0] && ft_strlen(tab[0]) != 0)
		return (parse_tab(tab, line, NULL));
	else
	{
		buf[0] = (char *)ft_memalloc(BUFF_SIZE + 1);
		return (3);
	}
}

static int		cache_fd(const int fd, char **buf, char **tab, char **line)
{
	int		ret;
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	ret = 1;
	temp = line[0];
	temp2 = NULL;
	if ((ret = check_tab(&tab[fd], line, buf)) != 3)
		return (ret);
	else
	{
		if ((ret = read(fd, buf[0], BUFF_SIZE)) != 0)
		{
			if (ret < 0)
				return (ret);
			return (parse_read(&tab[fd], buf, line, NULL));
		}
	}
	return (ft_strlen(*line) == 0 ? 0 : 1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*tab[2147483647];
	char			*buf;
	int				res;

	buf = NULL;
	if (fd >= 0 && line != NULL)
	{
		*line = ft_strnew(0);
		while ((res = cache_fd(fd, &buf, tab, line)))
		{
			ft_memdel((void **)&buf);
			if (res != 2)
				return (res);
		}
		ft_memdel((void **)&buf);
		ft_memdel((void *)&tab[fd]);
		return (res);
	}
	return (-1);
}
