/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:28:58 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:00 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	t_param	*param;

	param = prmcrt();
	g_iter = 0;
	g_rr = 0;
	va_start(ap, fmt);
	parsing_one(fmt, ap, param);
	va_end(ap);
	free(param);
	if (g_rr < 0)
		g_iter = -1;
	return (g_iter);
}

void	setflag(t_param **param, char f)
{
	if (f == '+')
		(*param)->pls = 1;
	else if (f == '-')
		(*param)->mns = 1;
	else if (f == '0')
		(*param)->nol = 1;
	else if (f == '#')
		(*param)->ht = 1;
	else if (f == ' ')
		(*param)->prbl = 1;
	else if (f == 'l' || f == 'L' || f == 'h' ||
				f == 'H' || f == 'j' || f == 'z')
		(*param)->lm = f;
	else if (ft_strchr("sSpdDioOuUxXcC%", f))
		(*param)->type = f;
}

void	setflag_dva(t_param **param, char *txt, int j, int flag)
{
	j++;
	if (flag == 1)
		(*param)->wdth = ft_atoi(txt);
	else if (flag == 2)
		(*param)->prcsn = ft_atoi(txt);
}

void	parsing_one(char *txt, va_list vl, t_param *param)
{
	int		*i;
	int		j;
	int		a;
	int		g;

	parsing_one_need(&i, &g, &a, &j);
	while (txt[*i] != '\0')
	{
		if (txt[*i] == '%')
		{
			if (txt[*i + 1] == '%')
			{
				*i = *i + 1 + write(1, "%", 1);
				g_iter++;
			}
			else if (txt[*i + 1] == '\0')
				*i = *i + 1;
			else
				*i = *i + parsing_two(&param, &txt[*i], vl);
		}
		else
			parsing_one_write(txt, i, j);
	}
}

void	parsing_one_need(int **i, int *g, int *a, int *j)
{
	*g = 0;
	*a = 0;
	*i = a;
	*j = 0;
}
