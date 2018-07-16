/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 20:48:42 by bgres             #+#    #+#             */
/*   Updated: 2018/06/05 20:48:43 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char		*check_t_ind(char *param, t_to_code *f,
	unsigned char *op, char position)
{
	unsigned int	mask;
	int				sdvig;

	mask = 0xff;
	sdvig = (8 * (3 - position));
	mask = mask << sdvig;
	if (param != NULL && (check_all_isdigit(param) == 0
		|| (check_all_isdigit(param) == 1 && ft_strlen(param) > 1
			&& param[0] == '-')))
	{
		*op = *op | (3 << (2 * (3 - position + 1)));
		return (param);
	}
	else if (param != NULL && param[0] == ':' && ft_strlen(param) > 1)
	{
		*op = *op | (3 << (2 * (3 - position + 1)));
		return (param);
	}
	else if (((f->op_f & mask) >> sdvig) <= 3)
	{
		g_error++;
		free(param);
		ft_printf("ERROR in check_t_ind line %d\n", g_line);
	}
	return (NULL);
}

char		*check_t_dir(char *param, t_to_code *f,
	unsigned char *op, int position)
{
	unsigned int	mask;
	int				sdvig;

	mask = 0xff;
	sdvig = (8 * (3 - position));
	mask = mask << sdvig;
	if (param != NULL && ft_strlen(param) >= 2 && param[0] == '%' &&
		(check_all_isdigit(&param[1]) == 0 || (ft_strlen(param) >= 3
			&& check_all_isdigit(&param[1]) == 1 && param[1] == '-')))
	{
		*op = *op | (2 << (2 * (3 - position + 1)));
		return (param);
	}
	else if (param != NULL && ft_strlen(param) >= 3
		&& param[0] == '%' && param[1] == ':')
	{
		*op = *op | (2 << (2 * (3 - position + 1)));
		return (param);
	}
	else if (((f->op_f & mask) >> sdvig) <= 3 && g_error++ >= 0)
	{
		ft_printf("Oops, youre T_DIR|%s feel bad on line %d\n", param, g_line);
		free(param);
	}
	return (NULL);
}

char		*check_t_dir_ind(char *param, t_to_code *f,
	unsigned char *op, int position)
{
	int				i;
	unsigned char	tmp;
	char			*ansver;

	tmp = *op;
	i = 0;
	ansver = check_t_dir(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	ansver = check_t_ind(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	g_error++;
	ft_printf("ERROR in param on line %d\n", g_line);
	free(param);
	return (NULL);
}

char		*check_t_dir_reg(char *param, t_to_code *f,
	unsigned char *op, int position)
{
	int				i;
	unsigned char	tmp;
	char			*ansver;

	tmp = *op;
	i = 0;
	ansver = check_t_dir(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	ansver = check_t_reg(param, f, op, position);
	if (tmp != *op)
		return (ansver);
	g_error++;
	ft_printf("ERROR in param on line %d\n", g_line);
	free(param);
	return (NULL);
}

char		*check_t_ind_reg(char *param, t_to_code *f,
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
	g_error++;
	ft_printf("ERROR in param on line %d\n", g_line);
	free(param);
	return (NULL);
}
