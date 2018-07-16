/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p10.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:40:30 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 21:40:31 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	need_4(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*write_n_c(char *line, int fd)
{
	int		i;
	int		j;
	char	*name;

	need_4(&i, &j);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\"' && (g_error++ >= 0))
		ft_printf("%s %d\n", ERROR_1, g_line);
	else
	{
		i++;
		while (line[i + j] != '\"' && line[i + j] != '\0')
			j++;
		if (line[i + j] != '\"')
			name = read_read(&line[i], fd);
		else
		{
			name = (char *)ft_memalloc((j + 2) * sizeof(char));
			while (--j >= 0)
				name[j] = line[i + j];
		}
		return (name);
	}
	return (NULL);
}

void	need_5(t_main *main_asm, int fd, char *line, int i)
{
	if ((main_asm->flag & 2) != 0 && (g_error++ >= 0))
		ft_printf("Oops, double comment, chek line %d\n", g_line);
	else
	{
		main_asm->flag = main_asm->flag | 2;
		main_asm->comment = write_n_c(&line[i + 8], fd);
	}
}

void	check_name_comment(char *line, t_main *main_asm, int fd)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '#' || line[i] == '\0')
		return ;
	if (ft_strnequ(&line[i], NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		if ((main_asm->flag & 1) != 0 && (g_error++ >= 0))
			ft_printf("Oops, double comment, chek line %d\n", g_line);
		else
		{
			main_asm->flag = main_asm->flag | 1;
			main_asm->name = write_n_c(&line[i + 5], fd);
		}
	}
	else if (ft_strnequ(&line[i], CCS, ft_strlen(CCS)))
		need_5(main_asm, fd, line, i);
	else if (g_error++ >= 0)
		ft_printf("Oops, somthing wrong on line %d\n", g_line);
}

int		check_sp(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '#')
		return (1);
	return (0);
}
