/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:29:05 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:07 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parsing_one_write(char *txt, int *i, int j)
{
	while (txt[*i + j] != '\0' && txt[*i + j] != '%')
		j++;
	g_iter += write(1, (txt + *i), j);
	*i = *i + j;
}

int		parsing_two(t_param **param, char *txt, va_list vl)
{
	int		i;
	int		j;

	j = parsing_two_need(&i, &j, 1);
	parsing_three(param, txt, " +-0#\0", &i);
	while (txt[i + j] != '\0' && ft_isdigit(txt[i + j]) == 1)
		j++;
	if (j > 0)
		setflag_dva(param, &txt[i], j, 1);
	j = parsing_two_need(&i, &j, 2);
	if (txt[i] == '.')
	{
		(*param)->tchka = 1;
		i++;
	}
	while (txt[i + j] != '\0' && ft_isdigit(txt[i + j]))
		j++;
	if (j > 0)
		setflag_dva(param, &txt[i], j, 2);
	j = parsing_two_need(&i, &j, 2);
	parsing_three(param, txt, "hljz\0", &i);
	check_p_end(param, txt, &i, vl);
	return (i);
}

int		parsing_two_need(int *i, int *j, int flag)
{
	if (flag == 1)
	{
		*i = 1;
		return (0);
	}
	else
	{
		*i = *i + *j;
		return (0);
	}
}

void	check_p_end(t_param **param, char *txt, int *i, va_list vl)
{
	char	*f;
	int		j;
	int		a;

	f = "sSpdDioOuUxXcC%\0";
	a = 0;
	j = 0;
	while (txt[*i] != '\0' && f[j] != '\0' && a == 0)
	{
		if (txt[*i] == f[j])
		{
			setflag(param, f[j]);
			a++;
			*i = *i + 1;
		}
		else
			j++;
	}
	if (a == 0)
	{
		c_print(*param, vl, txt[*i]);
		*i = *i + 1;
		(*param)->ror = 1;
	}
	check_p_end_need(param, vl);
}

void	check_p_end_need(t_param **param, va_list vl)
{
	if (ft_strchr("dDioOuUxX", (*param)->type) && (*param)->ror != 1)
		get_decimal(param, vl);
	else if ((*param)->type == 'p' && (*param)->ror != 1)
		p_printf(get_p(vl), *param);
	else if (ft_strchr("SC", (*param)->type) || (((*param)->lm == 'L' ||
			(*param)->lm == 'l') && ft_strchr("sc", (*param)->type)))
		p_utf(*param, vl);
	else if ((*param)->type == 'c' || (*param)->type == '%')
		c_print(*param, vl, -42);
	else if ((*param)->type == 's')
		s_print(*param, vl);
	prmssgn(param);
}
