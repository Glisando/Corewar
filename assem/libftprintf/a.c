/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:28:50 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:28:52 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		for_free_one(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
}

void		for_free_two(char *buf, char **line)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(buf, *line);
	free(tmp);
}

char		*ft_strndup(char *src, int n)
{
	size_t	i;
	char	*c;

	i = 0;
	while (src[i] != '\0' && (int)i < n)
		i++;
	c = (char *)malloc(sizeof(char) * i + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (src[i] != '\0' && (int)i < n)
	{
		c[i] = src[i];
		i++;
	}
	c[i] = '\0';
	if (ft_strequ("(null)", src))
		free(src);
	return (c);
}

t_param		*prmcrt(void)
{
	t_param *a;

	a = (t_param*)malloc(sizeof(t_param));
	prmssgn(&a);
	return (a);
}

void		prmssgn(t_param **a)
{
	(*a)->pls = -1;
	(*a)->mns = -1;
	(*a)->nol = -1;
	(*a)->ht = -1;
	(*a)->prbl = -1;
	(*a)->lm = -1;
	(*a)->type = -1;
	(*a)->tchka = -1;
	(*a)->ror = -1;
	(*a)->wdth = -1;
	(*a)->prcsn = -1;
}
