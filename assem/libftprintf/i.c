/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:30:00 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:30:01 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*for_digits(size_t n, t_param *a)
{
	size_t	len;
	char	*str;
	size_t	b;
	char	ch;

	b = 10;
	ch = (a->type == 'x' || a->type == 'p') ? 'a' : 'A';
	if (a->type == 'x' || a->type == 'X' || a->type == 'p')
		b = 16;
	if (a->type == 'o' || a->type == 'O')
		b = 8;
	len = ft_get_len(n, b);
	str = (char *)ft_memalloc(len + 1);
	if (n % b > 9)
		str[--len] = n % b + ch - 10;
	else
		str[--len] = n % b + '0';
	while (n /= b)
	{
		if (n % b > 9)
			str[--len] = n % b + ch - 10;
		else
			str[--len] = n % b + '0';
	}
	return (str);
}

void	p_printf_need(char **str, t_param *a, char *wdth)
{
	char *tmp;
	char *tmpp;

	for_free_two("0x", str);
	if ((int)ft_strlen(*str) < a->wdth)
	{
		if (a->mns == 1)
		{
			tmp = *str;
			tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
			*str = ft_strjoin(tmp, tmpp);
			free(tmp);
			free(tmpp);
		}
		else
		{
			tmp = *str;
			tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
			*str = ft_strjoin(tmpp, tmp);
			free(tmp);
			free(tmpp);
		}
	}
}

void	p_printf_needd(char **str, t_param *a, char *wdth)
{
	char *tmp;
	char *tmpp;

	a->wdth = a->wdth - 2;
	if ((int)ft_strlen(*str) < a->wdth)
	{
		if (a->mns != 1)
		{
			tmp = *str;
			tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
			*str = ft_strjoin(tmpp, tmp);
			free(tmp);
			free(tmpp);
			for_free_two("0x", str);
		}
	}
	else
		for_free_two("0x", str);
}

void	dvatri(char **str, t_param *a)
{
	char *tmp;
	char *tmpp;

	tmp = *str;
	tmpp = ft_stranew(a->prcsn - (int)ft_strlen(*str), "0");
	*str = ft_strjoin(tmpp, tmp);
	free(tmp);
	free(tmpp);
}

void	tritri(char **str, t_param *a, char *wdth)
{
	char *tmp;
	char *tmpp;

	tmp = *str;
	tmpp = ft_stranew(a->wdth - ft_strlen(*str), wdth);
	*str = ft_strjoin(tmp, tmpp);
	free(tmp);
	free(tmpp);
}
