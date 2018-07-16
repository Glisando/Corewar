/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p6.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:48:53 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 20:48:55 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	hvatit_5(t_comand ***f_list, unsigned char *i, int *j)
{
	*j = 0;
	*i = 0;
	if (*f_list == NULL)
		*f_list = make_f_list();
}

void	check_f(t_to_code *tmp, char *line)
{
	static t_comand		**f_list = NULL;
	unsigned char		i;
	int					j;
	char				*tmp2;

	hvatit_5(&f_list, &i, &j);
	if (line[i] == '#')
		return ;
	while (line[j] != ' ' && line[j] != '\t' && line[j] != '\0')
		j++;
	tmp2 = ft_copy_n(&line[0], j);
	j = 0;
	while (f_list[i++] != NULL)
	{
		if (ft_strequ(tmp2, f_list[i - 1]->name))
		{
			j = 1;
			hvatit_4(&tmp, f_list, i);
			f_full_check(&line[ft_strlen(tmp2)], f_list[i - 1], tmp);
			add_to_cmndlist(tmp);
		}
		if (i == 16 && j == 0 && g_error++ >= 0)
			ft_printf("%s %d\n", ERROR_3, g_line);
	}
	free(tmp2);
}

void	check_label(char *name)
{
	int		i;

	i = 0;
	while (name[i] != ':')
	{
		if (ft_strchr(LABEL_CHARS, name[i]) == NULL)
		{
			g_error++;
			ft_printf("%s %d\n", ERROR_2, g_line);
		}
		i++;
	}
}

void	hvatit_6(int *i, char *flag, t_to_code **tmp, int *j)
{
	*j = 0;
	*tmp = NULL;
	*flag = 0;
	*i = 0;
}

void	hvatit_7(t_to_code **tmp, char *line, int i, int j)
{
	(*tmp) = (t_to_code *)ft_memalloc(sizeof(t_to_code));
	(*tmp)->lbl = ft_copy_n(&line[i], j);
	check_label((*tmp)->lbl);
	add_to_cmndlist(*tmp);
}
