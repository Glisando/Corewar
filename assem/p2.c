/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:48:32 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 20:48:34 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_to_cmndlist(t_to_code *a)
{
	t_to_code	*tmp;

	tmp = NULL;
	if (g_cmndlist == NULL)
		g_cmndlist = a;
	else
	{
		tmp = g_cmndlist;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = a;
	}
}

char		*ft_copy_n(char *src, int n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = (char *)ft_memalloc(sizeof(char) * n + 1);
	if (!c)
		return (NULL);
	while (src[i] != '\0' && (int)i < n)
	{
		c[i] = src[i];
		i++;
	}
	return (c);
}

void		mfl1(t_comand **a)
{
	a[2] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[2]->name = ft_strdup(ST);
	a[2]->op = 1;
	a[2]->lz = 4;
	a[2]->args = 0x032300;
	a[2]->count = 2;
	a[2]->op_est = 1;
	a[2]->cmnd_l = 0;
	a[3] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[3]->name = ft_strdup(ADD);
	a[3]->op = 1;
	a[3]->lz = 4;
	a[3]->args = 0x030303;
	a[3]->count = 3;
	a[3]->op_est = 1;
	a[3]->cmnd_l = 5;
	mfl2(a);
}

void		mfl2(t_comand **a)
{
	a[4] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[4]->name = ft_strdup(SUB);
	a[4]->op = 1;
	a[4]->lz = 4;
	a[4]->args = 0x030303;
	a[4]->count = 3;
	a[4]->op_est = 1;
	a[4]->cmnd_l = 5;
	a[5] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[5]->name = ft_strdup(AND);
	a[5]->op = 1;
	a[5]->lz = 4;
	a[5]->args = 0xffff03;
	a[5]->count = 3;
	a[5]->op_est = 1;
	a[5]->cmnd_l = 0;
	a[6] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[6]->name = ft_strdup(OR);
	a[6]->op = 1;
	a[6]->lz = 4;
	a[6]->args = 0xffff03;
	a[6]->count = 3;
	a[6]->op_est = 1;
	a[6]->cmnd_l = 0;
	mfl3(a);
}

void		mfl3(t_comand **a)
{
	a[7] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[7]->name = ft_strdup(XOR);
	a[7]->op = 1;
	a[7]->lz = 4;
	a[7]->args = 0xffff03;
	a[7]->count = 3;
	a[7]->op_est = 1;
	a[7]->cmnd_l = 0;
	a[8] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[8]->name = ft_strdup(ZJMP);
	a[8]->op = 0;
	a[8]->lz = 2;
	a[8]->args = 0x010000;
	a[8]->count = 1;
	a[8]->op_est = 0;
	a[8]->cmnd_l = 3;
	a[9] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[9]->name = ft_strdup(LDI);
	a[9]->op = 1;
	a[9]->lz = 2;
	a[9]->args = 0xffff03;
	a[9]->count = 3;
	a[9]->op_est = 1;
	a[9]->cmnd_l = 0;
	mfl4(a);
}
