/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 20:07:26 by bgres             #+#    #+#             */
/*   Updated: 2018/05/11 20:07:29 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pars_two(char *line)
{
	int				i;
	char			flag;
	t_to_code		*tmp;
	int				j;

	hvatit_6(&i, &flag, &tmp, &j);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '#')
		return ;
	while (line[i + j] != ' ' && line[i + j] != '\t' && line[i + j] != '\0')
		j++;
	if (line[i] == '.' && g_error++ >= 0)
		ft_printf("error in line %d\n", g_line);
	if (j > 0 && line[i + j - 1] == ':')
	{
		hvatit_7(&tmp, line, i, j);
		flag = 1;
	}
	if (flag == 1 && (i += j) >= 1)
		while (line[i] == ' ' || line[i] == '\t')
			i++;
	if (line[i] == '#' || line[i] == '\0')
		return ;
	check_f(tmp, &line[i]);
}
