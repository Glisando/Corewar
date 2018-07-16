/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:29:41 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:43 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_print_for_unic(t_param *a, char *ch)
{
	char	*wdth;
	char	*tmp;
	char	*tmpp;

	if (a->nol == 1)
		wdth = "0";
	else
		wdth = " ";
	if ((int)ft_strlen(ch) < a->wdth)
	{
		tmp = ft_stranew(a->wdth - (int)ft_strlen(ch), wdth);
		tmpp = ch;
		if (a->mns == 1)
			ch = ft_strjoin(ch, tmp);
		else
			ch = ft_strjoin(tmp, ch);
		free(tmp);
	}
	g_iter = g_iter + write(1, ch, ft_strlen(ch));
}

char	c_print_need(char o, va_list vl, t_param *a)
{
	if (o > 0)
		return (o);
	else if (a->type == 'c')
		return ((char)va_arg(vl, int));
	else
		return ('%');
}

void	sem(char **ch, t_param *a, char *wdth, int r)
{
	char	*tmp;
	char	*tmpp;

	tmp = NULL;
	tmp = (char *)ft_stranew(a->wdth - r - (int)ft_strlen(*ch), wdth);
	if (a->mns == -1)
	{
		tmpp = *ch;
		*ch = ft_strjoin(tmp, *ch);
		free(tmpp);
	}
	else
	{
		tmpp = *ch;
		*ch = ft_strjoin(*ch, tmp);
		free(tmpp);
	}
	if (tmp)
		free(tmp);
}

void	c_print(t_param *a, va_list vl, char o)
{
	char	*ch;
	char	*wdth;
	int		r;

	r = 0;
	wdth = " ";
	if (a->nol == 1)
		wdth = "0";
	ch = ft_strnew(2);
	ch[0] = c_print_need(o, vl, a);
	if (ch[0] == 0)
		r = 1;
	if (1 < a->wdth)
		sem(&ch, a, wdth, r);
	write(1, ch, ft_strlen(ch));
	if (r == 1)
		g_iter = g_iter + write(1, "\0", 1);
	g_iter = g_iter + ft_strlen(ch);
	free(ch);
}

void	piatpiat(char **ch, t_param *a, int g, char *wdth)
{
	char		*tmp;
	char		*tmpp;

	tmp = *ch;
	tmpp = ft_stranew(a->wdth - (int)ft_strlen(*ch), wdth);
	*ch = ft_strjoin(tmp, tmpp);
	free(tmpp);
	if (g == 1)
		free(tmp);
}
