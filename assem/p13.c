/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p13.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:40:44 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 21:40:45 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

unsigned int	convert_t_ind(t_to_code *tmp, char *a)
{
	unsigned int	res;

	res = 0;
	if (a[0] == ':')
		return (magic_with_link2(tmp, a));
	res = ft_atoi_cw(a, 2);
	return (res);
}

void			zaebali_nazv(t_to_code *tmp, int i, char flag)
{
	if (flag == 1)
		tmp->args[i] = convert_t_reg(tmp->ar[i]);
	else if (flag == 2)
		tmp->args[i] = convert_t_dir(tmp, tmp->ar[i]);
	else if (flag == 3)
		tmp->args[i] = convert_t_ind(tmp, tmp->ar[i]);
}

void			convert_args(void)
{
	t_to_code	*tmp;
	char		i;

	i = -1;
	tmp = g_cmndlist;
	while (tmp)
	{
		while (++i < tmp->count)
			zaebali_nazv(tmp, i,
				(tmp->op & (3 << (2 * (3 - i)))) >> (2 * (3 - i)));
		i = -1;
		tmp = tmp->next;
	}
}

char			*make_name(char *a)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = ft_strlen(a) - 1;
	tmp = ft_memalloc(sizeof(char) * (i + 4));
	tmp[i++] = 'c';
	tmp[i++] = 'o';
	tmp[i++] = 'r';
	i = i - 4;
	while (i >= 0)
	{
		tmp[i] = a[i];
		i--;
	}
	return (tmp);
}

void			need(t_to_code *tmp, char *a)
{
	while (tmp)
	{
		if (tmp->lbl != NULL)
		{
			if (ft_strequ(tmp->lbl, a))
			{
				ft_printf("Oops, you have same label [%s]\n", a);
				g_error++;
			}
		}
		tmp = tmp->next;
	}
}
