/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:48:27 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 20:48:28 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		skip_space(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

void	need_need(char **line, char **tmp, char **tmp2)
{
	*tmp = *line;
	*line = ft_strjoin(*line, *tmp2);
	free(*tmp);
	*tmp = *line;
	*line = ft_strjoin(*line, "\n");
	free(*tmp);
	free(*tmp2);
	g_line++;
}

void	need_3(char **line, char **tmp, char **tmp2, int *i)
{
	*tmp = *line;
	*line = ft_strjoin(*line, *tmp2);
	free(*tmp);
	free(*tmp2);
	*i = 0;
}

void	r_r(char *tmp2)
{
	free(tmp2);
	exit(0);
}

char	*read_read(char *line, int fd)
{
	char	*tmp;
	char	*tmp2;
	char	*a;
	int		i;

	line = ft_strjoin(line, "\n");
	while (get_next_line(fd, &tmp2) > 0 && (a = ft_strchr(tmp2, '\"')) == NULL)
		need_need(&line, &tmp, &tmp2);
	g_line++;
	if (a == NULL && (g_error++ >= 0) && ft_printf("Oops, wheare \"?\n"))
		r_r(tmp2);
	else
	{
		need_3(&line, &tmp, &tmp2, &i);
		while (line[i] != '\"')
			i++;
		line[i++] = '\0';
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != '\0' && line[i] != '#' && (g_error++ >= 0))
			ft_printf("Oops, something wrong on line|%d|\n", g_line);
		return (line);
	}
	return ("(");
}
