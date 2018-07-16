/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p14.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 21:40:48 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 21:40:50 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_double_lbl(void)
{
	t_to_code	*tmp;

	tmp = g_cmndlist;
	while (tmp)
	{
		if (tmp->lbl != NULL)
			need(tmp->next, tmp->lbl);
		tmp = tmp->next;
	}
}

void	need2(char **av, t_main *main_asm, char *name)
{
	int		fd;
	char	a;

	fd = open(av[1], O_RDONLY);
	if (fd < 0 || ft_strlen(av[1]) < 3 || av[1][ft_strlen(av[1]) - 1] != 's'
		|| av[1][ft_strlen(av[1]) - 2] != '.' || ft_strlen(av[1]) < 3
		|| read(fd, &a, 0) == -1 || ft_printf("Oops, wrong file\n"))
		return ;
	main_asm = start_pars(fd);
	if (g_error > 0 || ft_strlen(main_asm->name) > PROG_NAME_LENGTH
		|| ft_strlen(main_asm->comment) > COMMENT_LENGTH)
	{
		ft_printf("Oops, you hawe %d errors\n", g_error);
	}
	else
	{
		count_cmnd_len(NULL);
		check_double_lbl();
		convert_args();
		start_write(make_name(av[1]), main_asm);
		name = make_name(av[1]);
		ft_printf("vse zbs file %s sdelan cmndL\n", name, g_cmnd_len);
		free(name);
	}
}

void	free_list(void)
{
	int			i;
	t_to_code	*tmp;

	tmp = g_cmndlist;
	while (tmp)
	{
		if (tmp->lbl != NULL)
			free(tmp->lbl);
		if (tmp->f_name != NULL)
			free(tmp->f_name);
		i = 0;
		while (i < 4)
		{
			if (tmp->ar[i] != NULL)
				free(tmp->ar[i]);
			i++;
		}
		free(tmp);
		tmp = tmp->next;
	}
}

void	nado_1(void)
{
	g_line = 0;
	g_error = 0;
	g_cmndlist = NULL;
	g_cmnd_len = 0;
}

void	nado_2(t_main *main_asm, char *name)
{
	if (g_error > 0)
		ft_printf("Oops, you hawe %d errors in file %s\n", g_error, name);
	if (main_asm->name != NULL && ft_strlen(main_asm->name) > PROG_NAME_LENGTH)
		ft_printf("Oops, youre name too big\n");
	if (main_asm->comment != NULL &&
		ft_strlen(main_asm->comment) > COMMENT_LENGTH)
		ft_printf("Oops, youre comment too big\n");
	if (g_cmnd_len > CHAMP_MAX_SIZE)
		ft_printf("Oops, youre bot too big\n");
}
