/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:41:48 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:41:50 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	tricheturi(char **str, t_param *a, char *wdth)
{
	char	*tmp;
	char	*tmpp;

	tmp = *str;
	tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
	*str = ft_strjoin(tmpp, tmp);
	free(tmp);
	free(tmpp);
}

void	itoa_printf_need(t_param *a, char **str, char *wdth, int zn)
{
	if ((int)ft_strlen(*str) < a->prcsn && a->prcsn != -1)
		dvatri(str, a);
	if (zn == -1 && ((a->nol != 1 || (int)ft_strlen(*str) > a->wdth)
		|| a->wdth < 0 || a->mns == 1))
		for_free_two("-", str);
	else if (a->pls == 1 && (a->nol != 1 ||
		(int)ft_strlen(*str) > a->wdth) && ft_strchr("dDi", a->type) && zn > 0)
		for_free_two("+", str);
	else if (a->prbl == 1 && (a->nol != 1 ||
		(int)ft_strlen(*str) > a->wdth) && ft_strchr("dDi", a->type))
		for_free_two(" ", str);
	if ((int)ft_strlen(*str) < a->wdth && a->wdth != -1)
	{
		if (a->mns == 1)
			tritri(str, a, wdth);
		else
		{
			tricheturi(str, a, wdth);
			plz(str, a, zn);
		}
	}
}

void	dvadva(char **str, t_param *a)
{
	char	*tmp;
	char	*tmpp;

	tmp = *str;
	tmpp = ft_stranew(-(int)ft_strlen(*str) + a->prcsn, "0");
	*str = ft_strjoin(tmpp, tmp);
	free(tmp);
	free(tmpp);
}

void	itoa_printf_need_dva(t_param *a, char **str, char *wdth, size_t w)
{
	char	*tmp;
	char	*tmpp;

	if (a->prcsn >= 0 && (int)ft_strlen(*str) < a->prcsn && a->tchka == 1)
		dvadva(str, a);
	if (a->ht == 1 && wdth[0] == ' ' && w != 0)
		razraz(a, str, wdth);
	else if (a->ht == 1 && wdth[0] == 48 && w != 0)
		razdva(a, str, wdth);
	else
	{
		if ((int)ft_strlen(*str) < a->wdth)
		{
			tmp = *str;
			tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
			if (a->mns == 1)
				*str = ft_strjoin(*str, tmpp);
			else
				*str = ft_strjoin(tmpp, *str);
			free(tmp);
			free(tmpp);
		}
	}
}

void	razraz(t_param *a, char **str, char *wdth)
{
	char	*tmp;
	char	*tmpp;

	if (a->type == 'x')
		for_free_two("0x", str);
	else if (a->type == 'X')
		for_free_two("0X", str);
	else if (a->type == 'o' && *str[0] != '0')
		for_free_two("0", str);
	if ((int)ft_strlen(*str) < a->wdth)
	{
		tmp = *str;
		tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
		if (a->mns == 1)
			*str = ft_strjoin(*str, tmpp);
		else
			*str = ft_strjoin(tmpp, *str);
		free(tmp);
		free(tmpp);
	}
}
