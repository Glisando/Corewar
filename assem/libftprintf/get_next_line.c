/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:58:05 by bgres             #+#    #+#             */
/*   Updated: 2018/01/22 16:58:07 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cheturi(char **line, t_nada *telo)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, telo->buf);
	free(tmp);
}

void	dva(t_nada *telo, int fd, char **line)
{
	while (read(fd, telo->buf, BUFF_SIZE)
	&& (ft_strchr(telo->buf, '\n')) == NULL)
	{
		cheturi(line, telo);
		ft_bzero(telo->tmp, BUFF_SIZE + 1);
		telo->buf = telo->tmp;
	}
	if (ft_strchr(telo->buf, '\n') != NULL)
	{
		telo->buf[ft_strchr(telo->buf, '\n') - telo->buf] = '\0';
		cheturi(line, telo);
		telo->buf = ft_strchr(telo->buf, '\0') + 1;
		telo->flag = telo->flag / 10 * 10 + 1;
		telo->flag = telo->flag % 10 + 10;
	}
	else
	{
		cheturi(line, telo);
		ft_bzero(telo->tmp, BUFF_SIZE + 1);
		telo->buf = telo->tmp;
		telo->flag = 101;
	}
}

void	tri(t_nada *telo, char **line)
{
	char	*tmp;

	tmp = *line;
	if (ft_strchr(telo->buf, '\n') != NULL)
	{
		telo->buf[ft_strchr(telo->buf, '\n') - telo->buf] = '\0';
		*line = ft_strjoin(*line, telo->buf);
		free(tmp);
		telo->buf = ft_strchr(telo->buf, '\0') + 1;
		telo->flag = telo->flag / 10 * 10 + 1;
		telo->flag = telo->flag % 10 + 10;
	}
	else
	{
		*line = ft_strjoin(*line, telo->buf);
		ft_bzero(telo->tmp, BUFF_SIZE + 1);
		telo->buf = telo->tmp;
		free(tmp);
		telo->flag = 1;
	}
}

int		raz(t_nada *telo, int fd, char **line)
{
	char	a;

	if ((fd < 0 || line == NULL || read(fd, &a, 0) < 0))
		return (-1);
	*line = (char *)ft_memalloc(2 * sizeof(char));
	while (1)
	{
		if ((telo->flag / 10 % 10) == 1)
			tri(telo, line);
		if ((telo->flag / 10 % 10) == 0)
		{
			ft_bzero(telo->tmp, BUFF_SIZE + 1);
			telo->buf = telo->tmp;
			dva(telo, fd, line);
		}
		if (telo->flag / 100 == 1 &&
		ft_strlen(*line) == 0 && telo->flag / 10 % 10 == 0)
			return (0);
		if (telo->flag % 10 == 1)
			return (1);
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_nada	*head;
	t_nada			*telo;

	if (!head)
	{
		head = (t_nada *)malloc(sizeof(t_nada));
		head->fd = -100;
		head->next = NULL;
	}
	telo = head;
	while (telo->fd != fd && telo->next != NULL)
		telo = telo->next;
	if (telo->fd != fd)
	{
		telo->next = (t_nada *)malloc(sizeof(t_nada));
		telo = telo->next;
		telo->fd = fd;
		telo->buf = (char *)ft_memalloc(BUFF_SIZE + 1);
		telo->tmp = telo->buf;
		telo->next = NULL;
		telo->flag = 0;
	}
	return (raz(telo, fd, line));
}
