/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_code.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 15:35:38 by bgres             #+#    #+#             */
/*   Updated: 2018/05/26 15:35:40 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_t_reg(t_to_code *tmp, int fd, int i)
{
	char	a;

	a = tmp->args[i] & 0xff;
	write(fd, &a, 1);
}

void	write_comand(int fd)
{
	t_to_code	*tmp;
	int			i;

	tmp = g_cmndlist;
	while (tmp)
	{
		if (tmp->first_b != 0)
		{
			write(fd, &tmp->first_b, 1);
			if (tmp->op_est != 0)
				write(fd, (char *)&tmp->op, 1);
			i = 0;
			while (i < tmp->count)
			{
				if (tmp->ar[i][0] == 'r')
					write_t_reg(tmp, fd, i);
				else if (tmp->ar[i][0] == '%')
					write_t_dir(tmp, fd, i);
				else
					write_short(fd, tmp->args[i]);
				i++;
			}
		}
		tmp = tmp->next;
	}
}

void	start_write(char *name, t_main *main_asm)
{
	t_to_code	*tmp;
	int			fd;
	int			i;

	i = 0;
	tmp = g_cmndlist;
	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write_int(fd, COREWAR_EXEC_MAGIC);
	write_name(fd, main_asm);
	write_comand(fd);
	free(name);
}
