/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:18:13 by bgres             #+#    #+#             */
/*   Updated: 2018/01/24 14:18:20 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	razdva(t_param *a, char **str, char *wdth)
{
	char	*tmp;
	char	*tmpp;

	a->wdth -= (a->type == 'o') ? 1 : 2;
	if ((int)ft_strlen(*str) < a->wdth)
	{
		if (a->mns != 1)
		{
			tmp = *str;
			tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
			*str = ft_strjoin(tmpp, *str);
			free(tmpp);
			free(tmp);
			if (a->type == 'x')
				for_free_two("0x", str);
			else if (a->type == 'X')
				for_free_two("0X", str);
			else if (a->type == 'o' && *str[0] != '0')
				for_free_two("0", str);
		}
	}
}

void	itoa_printf(size_t n, t_param *a, int zn)
{
	char			*str;
	char			*wdth;
	size_t			w;

	w = n;
	if (a->prcsn <= 0 && a->tchka == 1 &&
		n == 0 && a->type == 'o' && a->ht == 1)
		str = ft_stranew(1, "0");
	else if (a->prcsn <= 0 && a->tchka == 1 && n == 0)
		str = ft_strnew(1);
	else
		str = for_digits(n, a);
	wdth = " ";
	if (a->nol == 1 && a->tchka == -1 && a->mns == -1)
		wdth = "0";
	if (ft_strchr("XxOo", a->type) == NULL)
		itoa_printf_need(a, &str, wdth, zn);
	else
		itoa_printf_need_dva(a, &str, wdth, w);
	g_iter = g_iter + write(1, str, ft_strlen(str));
	free(str);
}

void	plz(char **str, t_param *a, int zn)
{
	if ((a->pls == 1) && a->nol == 1 && zn > 0)
		*str[0] = '+';
	else if ((a->prbl == 1) && a->nol == 1)
		*str[0] = ' ';
	else if (zn == -1 && a->nol == 1)
		*str[0] = '-';
}
