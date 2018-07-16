/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p12.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:40:39 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 21:40:41 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				ft_strequ_cw(char const *s1, char const *s2)
{
	int		i;

	if (s1 && s2)
	{
		i = 0;
		while (s1[i] != ':' || s2[i] != '\0')
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

unsigned int	magic_with_link(t_to_code *tmp, char *a)
{
	t_to_code	*tmp2;

	tmp2 = g_cmndlist;
	while (tmp2)
	{
		if (tmp2->first_b == 0 && ft_strequ_cw(tmp2->lbl, &a[2]))
			return ((unsigned int)(tmp2->cmnd_i - tmp->cmnd_i));
		tmp2 = tmp2->next;
	}
	ft_printf("Oops, there is no such label [%s]\n", a);
	g_error++;
	return ('(');
}

unsigned int	magic_with_link2(t_to_code *tmp, char *a)
{
	t_to_code	*tmp2;

	tmp2 = g_cmndlist;
	while (tmp2)
	{
		if (tmp2->first_b == 0 && ft_strequ_cw(tmp2->lbl, &a[1]))
			return ((unsigned int)(tmp2->cmnd_i - tmp->cmnd_i));
		tmp2 = tmp2->next;
	}
	ft_printf("Oops, there is no such label[%s]\n", a);
	g_error++;
	return ('(');
}

unsigned int	convert_t_reg(char *a)
{
	unsigned int	res;

	if (ft_strlen(a) > 1 && ft_strlen(a) < 4)
	{
		res = -1;
		res = ft_atoi(&a[1]);
		if (res > 16)
			ft_printf("Warning, youre T_REG > 16\n");
		return (res);
	}
	ft_printf("Oops, youre T_REG-[%a] feels bad\n");
	g_error++;
	return (-1);
}

unsigned int	convert_t_dir(t_to_code *tmp, char *a)
{
	unsigned int	res;

	res = 0;
	if (a[1] == ':')
		return (magic_with_link(tmp, a));
	else
		res = ft_atoi_cw(&a[1], tmp->lz);
	return (res);
}
