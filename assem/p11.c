/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p11.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:40:35 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 21:40:36 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	do_whot_need(char *line)
{
	int		i;

	i = 0;
	if (ft_strchr(line, '#') != NULL)
	{
		while (line[i] != '#')
			i++;
		line[i] = '\0';
	}
}

void	need_6(t_main *main_asm)
{
	if (main_asm->name == NULL || main_asm->comment == NULL)
	{
		if (main_asm->name == NULL && g_error++ >= 0)
			ft_printf("Oops, no name (\n");
		if (main_asm->comment == NULL && g_error++ >= 0)
			ft_printf("Oops, no comment(\n");
	}
}

t_main	*start_pars(int fd)
{
	char		*line;
	t_main		*main_asm;
	t_comand	*all_comand;

	main_asm = (t_main *)ft_memalloc(sizeof(t_main));
	all_comand = (t_comand *)ft_memalloc(sizeof(t_comand));
	while (get_next_line(fd, &line) && ++g_line)
	{
		if (line[0] != '#' && ft_strlen(line) != 0 && check_sp(line)
			!= 1 && ((main_asm->flag & 3) != 3))
			check_name_comment(line, main_asm, fd);
		else if (line[0] != '#' && check_sp(line) != 1 && ft_strlen(line) != 0)
		{
			do_whot_need(line);
			pars_two(line);
		}
		free(line);
	}
	need_6(main_asm);
	free(line);
	free(all_comand);
	return (main_asm);
}

void	need_7(t_to_code *tmp, t_comand **f, char a[4], unsigned char mask)
{
	int		i;

	i = 1;
	if (tmp->first_b != 0 && f[tmp->first_b - 1]->cmnd_l == 0)
	{
		a[2] = f[tmp->first_b - 1]->lz;
		i = i + f[tmp->first_b - 1]->op + a[(tmp->op & (mask << 6)) >> 6]
		+ a[(tmp->op & (mask << 4)) >> 4] + a[(tmp->op & (mask << 2)) >> 2];
		tmp->cmnd_l = i;
		tmp->cmnd_i = g_cmnd_len;
		g_cmnd_len += i;
	}
	else if (tmp->first_b != 0)
	{
		tmp->cmnd_i = g_cmnd_len;
		tmp->cmnd_l = f[tmp->first_b - 1]->cmnd_l;
		g_cmnd_len += f[tmp->first_b - 1]->cmnd_l;
	}
	else
	{
		tmp->cmnd_i = g_cmnd_len;
		tmp->cmnd_l = -1;
	}
}

void	count_cmnd_len(t_comand **f)
{
	t_to_code		*tmp;
	int				i;
	unsigned char	mask;
	char			a[4];

	f = make_f_list();
	a[0] = 0;
	a[1] = 1;
	a[3] = 2;
	mask = 0x3;
	i = 1;
	tmp = g_cmndlist;
	while (tmp)
	{
		need_7(tmp, f, a, mask);
		tmp = tmp->next;
	}
	i = 0;
	while (f[i] != NULL)
	{
		free(f[i]->name);
		free(f[i]);
		i++;
	}
	free(f);
}
