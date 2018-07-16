/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:29:49 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:50 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	piat(char **ch, t_param *a, int g, char *wdth)
{
	char		*tmp;
	char		*tmpp;

	tmp = *ch;
	tmpp = ft_stranew(a->wdth - (int)ft_strlen(*ch), wdth);
	*ch = ft_strjoin(tmpp, tmp);
	free(tmpp);
	if (g == 1)
		free(tmp);
}

void	shest(char **ch, int *g)
{
	if (*g == 1)
		free(*ch);
	*ch = ft_strnew(1);
	*g = 1;
}

void	shestshrst(char **ch, int *g, t_param *a)
{
	char	*tmp;

	tmp = *ch;
	*ch = ft_strndup(*ch, a->prcsn);
	if (*g == 1)
		free(tmp);
	*g = 1;
}

void	s_print(t_param *a, va_list vl)
{
	char	*ch;
	char	*wdth;
	int		g;

	g = 0;
	wdth = " ";
	if (a->nol == 1)
		wdth = "0";
	ch = (char *)va_arg(vl, char *);
	if (ch == NULL && (g = 1))
		ch = ft_strdup("(null)");
	if (a->tchka == 1 && a->prcsn <= 0)
		shest(&ch, &g);
	if (a->prcsn > -1)
		shestshrst(&ch, &g, a);
	if ((int)ft_strlen(ch) < a->wdth)
	{
		if (a->mns == 1)
			piatpiat(&ch, a, g, wdth);
		else
			piat(&ch, a, g, wdth);
	}
	g_iter = g_iter + write(1, ch, ft_strlen(ch));
	if (g == 1)
		free(ch);
}

void	p_printf(size_t n, t_param *a)
{
	char		*str;
	char		*wdth;

	wdth = " ";
	if (a->prcsn <= 0 && a->tchka == 1 && n == 0)
		str = ft_strnew(1);
	else
		str = for_digits(n, a);
	if (a->nol == 1 && a->tchka == -1 && a->mns == -1)
		wdth = "0";
	if (a->prcsn >= 0 && (int)ft_strlen(str) < a->prcsn && a->tchka == 1)
		dvatri(&str, a);
	if (wdth[0] == ' ')
		p_printf_need(&str, a, wdth);
	else if (wdth[0] == 48)
		p_printf_needd(&str, a, wdth);
	g_iter = g_iter + write(1, str, ft_strlen(str));
	free(str);
}
