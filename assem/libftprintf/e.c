/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:29:20 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:21 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*for_bits_check_mmmm(wint_t ch, t_param *a)
{
	char	*buf;

	buf = ft_strnew(5);
	buf[3] = ((ch & 0x0000003f) | 0x00000080) & 0xffffffbf;
	buf[2] = (((0x00000fc0 & ch) >> 6) | 0x00000080) & 0xffffffbf;
	buf[1] = ((0x0003f000 & ch) >> 12 | 0x00000080) & 0xffffffbf;
	buf[0] = (((0x00007000 & ch) >> 18) | 0x000000f0) & 0xfffffff7;
	if (ch == 0 && (a->type == 'S' || a->type == 's'))
	{
		free(buf);
		return ("\0");
	}
	else if (a->type == 'C' || a->type == 'c')
	{
		g_iter = g_iter + 4;
		write(1, buf, 4);
	}
	else if (a->type == 's' || a->type == 'S')
	{
		if ((a->prcsn = a->prcsn - 4) >= 0 || a->tchka == -1)
			return (buf);
	}
	free(buf);
	buf = ft_strnew(0);
	return (buf);
}

void	vosem(char **stroka, wint_t ch, t_param *a, int j)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = *stroka;
	if (j <= 7)
		tmp2 = for_bits_check_m(ch, a);
	else if (j <= 11)
		tmp2 = for_bits_check_mm(ch, a);
	else if (j <= 16)
		tmp2 = for_bits_check_mmm(ch, a);
	else
		tmp2 = for_bits_check_mmmm(ch, a);
	*stroka = ft_strjoin(*stroka, tmp2);
	free(tmp1);
	free(tmp2);
}

void	for_bits(wint_t ch, t_param *a, char **stroka)
{
	int		j;

	if (ch == 0 && (a->type == 'c' || a->type == 'C'))
	{
		if (a->type == 'C')
		{
			g_iter = g_iter + write(1, "\0", 1);
			return ;
		}
	}
	j = for_bits_need(ch);
	j = for_bits_check_mcm(j);
	if (j <= 7)
		vosem(stroka, ch, a, j);
	else if (j <= 11)
		vosem(stroka, ch, a, j);
	else if (j <= 16)
		vosem(stroka, ch, a, j);
	else
		vosem(stroka, ch, a, j);
}

void	p_utf(t_param *a, va_list vl)
{
	wchar_t	*s;
	wint_t	ch;
	char	*stroka;

	stroka = ft_strnew(1);
	if (a->type == 'C' || a->type == 'c')
	{
		ch = va_arg(vl, wint_t);
		for_bits(ch, a, &stroka);
		free(stroka);
	}
	else
	{
		s = va_arg(vl, wchar_t *);
		if (s == NULL)
			g_iter = g_iter + write(1, "(null)", 6);
		else
		{
			while (*s != '\0' && (a->prcsn > 0 || a->tchka == -1))
				for_bits(*(s++), a, &stroka);
			s_print_for_unic(a, stroka);
			free(stroka);
		}
	}
}

void	parsing_three(t_param **param, char *txt, char *f, int *i)
{
	int		j;

	j = 0;
	while (txt[*i] != '\0' && f[j] != '\0')
	{
		if (txt[*i] == f[j])
		{
			if ((txt[*i] == 'h' && txt[*i + 1] == 'h') ||
				(txt[*i] == 'l' && txt[*i + 1] == 'l'))
			{
				setflag(param, txt[*i] - 32);
				if (txt[*i] != '\0')
					*i = *i + 2;
			}
			else
			{
				setflag(param, f[j]);
				j = 0;
				*i = *i + 1;
			}
		}
		else
			j++;
	}
}
