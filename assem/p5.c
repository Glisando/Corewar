/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p5.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:48:48 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 20:48:50 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*check_t_ind_reg_dir(char *param, t_to_code *f,
	unsigned char *op, int position)
{
	int				i;
	unsigned char	tmp;
	char			*ansver;

	tmp = *op;
	i = 0;
	ansver = check_t_ind(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	ansver = check_t_reg(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	ansver = check_t_dir(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	g_error++;
	ft_printf("ERROR in param on line %d\n", g_line);
	free(param);
	return (NULL);
}

void	hvatit_1(int a, int *sdvig, unsigned int *mask, int *flag)
{
	*sdvig = (8 * (3 - a));
	*flag = 0;
	*mask = 0xff;
	*mask = *mask << *sdvig;
}

int		get_need_f(char *param, int a, t_comand *f, t_to_code *tmp)
{
	unsigned int	mask;
	int				flag;
	int				sdvig;
	unsigned char	op;

	op = 0;
	hvatit_1(a, &sdvig, &mask, &flag);
	if (((f->args & mask) >> sdvig) == 0x01)
		tmp->ar[a - 1] = check_t_dir(param, tmp, &op, a);
	else if (((f->args & mask) >> sdvig) == 0x02)
		tmp->ar[a - 1] = check_t_ind(param, tmp, &op, a);
	else if (((f->args & mask) >> sdvig) == 0x03)
		tmp->ar[a - 1] = check_t_reg(param, tmp, &op, a);
	else if (((f->args & mask) >> sdvig) == 0x12)
		tmp->ar[a - 1] = check_t_dir_ind(param, tmp, &op, a);
	else if (((f->args & mask) >> sdvig) == 0x13)
		tmp->ar[a - 1] = check_t_dir_reg(param, tmp, &op, a);
	else if (((f->args & mask) >> sdvig) == 0x23)
		tmp->ar[a - 1] = check_t_ind_reg(param, tmp, &op, a);
	else if (((f->args & mask) >> sdvig) == 0xff)
		tmp->ar[a - 1] = check_t_ind_reg_dir(param, tmp, &op, a);
	else
		ft_printf("kakoito pzdc\n");
	tmp->op = tmp->op | op;
	return (flag);
}

void	f_full_check(char *line, t_comand *f, t_to_code *tmp)
{
	int		i;
	char	**args;
	int		j;

	j = 0;
	i = -1;
	args = ft_strsplit(line, ',');
	while (args[++i] != NULL)
		args[i] = ft_strtrim_cw(args[i]);
	i = 0;
	while (args[i] != NULL)
		i++;
	if (i != f->count && g_error++ >= 0)
	{
		ft_printf("not that number of arguments on line %d\n", g_line);
		j = 0;
		while (j < i)
			free(args[j++]);
		free(args);
		return ;
	}
	i = -1;
	while (args[++i] != NULL)
		get_need_f(args[i], i + 1, f, tmp);
	free(args);
}

void	hvatit_4(t_to_code **tmp, t_comand **f_list, int i)
{
	(*tmp) = (t_to_code *)ft_memalloc(sizeof(t_to_code));
	(*tmp)->first_b = i;
	(*tmp)->op_est = f_list[i - 1]->op_est;
	(*tmp)->op_f = f_list[i - 1]->args;
	(*tmp)->count = f_list[i - 1]->count;
	(*tmp)->lz = f_list[i - 1]->lz;
}
