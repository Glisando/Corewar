/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:48:38 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 20:48:39 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			mfl4(t_comand **a)
{
	a[10] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[10]->name = ft_strdup(STI);
	a[10]->op = 1;
	a[10]->lz = 2;
	a[10]->args = 0x03ff13;
	a[10]->count = 3;
	a[10]->op_est = 1;
	a[10]->cmnd_l = 0;
	a[11] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[11]->name = ft_strdup(FORK);
	a[11]->op = 0;
	a[11]->lz = 2;
	a[11]->args = 0x010000;
	a[11]->count = 1;
	a[11]->op_est = 0;
	a[11]->cmnd_l = 3;
	a[12] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[12]->name = ft_strdup(LLD);
	a[12]->op = 1;
	a[12]->lz = 4;
	a[12]->args = 0x120300;
	a[12]->count = 2;
	a[12]->op_est = 1;
	a[12]->cmnd_l = 0;
	mfl5(a);
}

void			mfl5(t_comand **a)
{
	a[13] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[13]->name = ft_strdup(LLDI);
	a[13]->op = 1;
	a[13]->lz = 2;
	a[13]->args = 0xff1303;
	a[13]->count = 3;
	a[13]->op_est = 1;
	a[13]->cmnd_l = 0;
	a[14] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[14]->name = ft_strdup(LFORK);
	a[14]->op = 0;
	a[14]->lz = 2;
	a[14]->args = 0x010000;
	a[14]->count = 1;
	a[14]->op_est = 0;
	a[14]->cmnd_l = 3;
	a[15] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[15]->name = ft_strdup(AFF);
	a[15]->op = 1;
	a[15]->lz = 4;
	a[15]->args = 0x030000;
	a[15]->count = 1;
	a[15]->op_est = 1;
	a[15]->cmnd_l = 3;
}

t_comand		**make_f_list(void)
{
	t_comand	**a;

	a = (t_comand **)malloc(sizeof(t_comand *) * 17);
	a[0] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[0]->name = ft_strdup(LIVE);
	a[0]->op = 0;
	a[0]->lz = 4;
	a[0]->args = 0x010000;
	a[0]->count = 1;
	a[0]->op_est = 0;
	a[0]->cmnd_l = 5;
	a[1] = (t_comand *)ft_memalloc(sizeof(t_comand));
	a[1]->name = ft_strdup(LD);
	a[1]->op = 1;
	a[1]->lz = 4;
	a[1]->args = 0x120300;
	a[1]->count = 2;
	a[1]->op_est = 1;
	a[1]->cmnd_l = 0;
	a[16] = NULL;
	mfl1(a);
	return (a);
}

int				check_all_isdigit(char *param)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (param[i] != '\0')
	{
		if (!ft_isdigit(param[i]))
			a++;
		i++;
	}
	return (a);
}

char			*check_t_reg(char *param, t_to_code *f,
	unsigned char *op, char position)
{
	unsigned int	mask;
	int				sdvig;

	mask = 0xff;
	sdvig = (8 * (3 - position));
	mask = mask << sdvig;
	if (ft_strlen(param) >= 2 && ft_strlen(param) <= 3
		&& param[0] == 'r' && ft_isdigit(param[1])
		&& (ft_isdigit(param[2]) || param[2] == '\0'))
	{
		*op = *op | (1 << (2 * (3 - position + 1)));
		return (param);
	}
	else if (((f->op_f & mask) >> sdvig) <= 3)
	{
		g_error++;
		free(param);
		ft_printf("ERROR in t_reg=[%s] on line line=%d\n", param, g_line);
	}
	return (NULL);
}
