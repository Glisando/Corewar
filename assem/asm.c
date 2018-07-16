/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 12:43:39 by bgres             #+#    #+#             */
/*   Updated: 2018/05/09 12:43:41 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	nado_3(int fd, t_main **main_asm)
{
	nado_1();
	*main_asm = start_pars(fd);
	count_cmnd_len(NULL);
	check_double_lbl();
	convert_args();
}

void	free_2(t_main *main_asm, char *name)
{
	free(name);
	if (main_asm->name != NULL)
		free(main_asm->name);
	if (main_asm->comment != NULL)
		free(main_asm->comment);
	free_list();
	if (main_asm != NULL)
		free(main_asm);
}

int		pzdc1(t_main *main_asm)
{
	if (g_error > 0 || ft_strlen(main_asm->name) > PROG_NAME_LENGTH
		|| ft_strlen(main_asm->comment) > COMMENT_LENGTH
		|| g_cmnd_len > CHAMP_MAX_SIZE)
		return (1);
	return (0);
}

int		pzdc2(int fd, int i, char **av)
{
	if (fd < 0 || ft_strlen(av[i]) < 3
		|| av[i][ft_strlen(av[i]) - 1] != 's'
		|| av[i][ft_strlen(av[i]) - 2] != '.' || ft_strlen(av[i]) < 3)
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int			fd;
	t_main		*main_asm;
	char		*name;
	int			i;

	i = 0;
	if (ac < 2 && ft_printf("no argument\n"))
		return (0);
	while (++i < ac)
	{
		fd = open(av[i], O_RDONLY);
		if (pzdc2(fd, i, av))
			ft_printf("wrong file n-%i\n", i - 1);
		else
		{
			nado_3(fd, &main_asm);
			name = make_name(av[i]);
			if (pzdc1(main_asm))
				nado_2(main_asm, name);
			else if (ft_printf("Congratulation, file %s was made!\n", name))
				start_write(make_name(av[i]), main_asm);
			free_2(main_asm, name);
		}
	}
	return (0);
}
