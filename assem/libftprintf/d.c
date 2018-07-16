/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:29:12 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:14 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		for_bits_need(wint_t ch)
{
	int				j;
	unsigned int	i;

	j = 0;
	i = 0x80000000;
	while ((i & ch) == 0 && i > 0)
	{
		j++;
		i = i / 2;
	}
	return (32 - j);
}

int		for_bits_check_mcm(int j)
{
	if (MB_CUR_MAX == 1 && j > 7)
	{
		g_rr = -1;
		return (6);
	}
	else if (MB_CUR_MAX == 2 && j > 11)
	{
		g_rr = -1;
		return (10);
	}
	else if (MB_CUR_MAX == 3 && j > 16)
	{
		g_rr = -1;
		return (15);
	}
	else
		return (j);
}

char	*for_bits_check_m(wint_t ch, t_param *a)
{
	char			*buf;

	buf = ft_strnew(5);
	buf[0] = ch & 0xff;
	if (ch == 0 && (a->type == 'S' || a->type == 's'))
	{
		free(buf);
		return ("\0");
	}
	else if (a->type == 'C' || a->type == 'c')
	{
		g_iter++;
		write(1, buf, 1);
	}
	else if (a->type == 's' || a->type == 'S')
	{
		if (a->prcsn - 1 >= 0 || a->tchka == -1)
		{
			a->prcsn -= 1;
			return (buf);
		}
	}
	free(buf);
	buf = ft_strnew(0);
	return (buf);
}

char	*for_bits_check_mm(wint_t ch, t_param *a)
{
	char	*buf;

	buf = ft_strnew(5);
	buf[1] = ((ch & 0x3f) | 0x80) & 0xffffffbf;
	buf[0] = (((0x00000fc0 & ch) >> 6) | 0x000000c0) & 0xfffffdf;
	if (ch == 0 && (a->type == 'S' || a->type == 's'))
	{
		free(buf);
		return ("\0");
	}
	else if (a->type == 'C' || a->type == 'c')
	{
		g_iter = g_iter + 2;
		write(1, buf, 2);
	}
	else if (a->type == 's' || a->type == 'S')
	{
		if ((a->prcsn = a->prcsn - 2) >= 0 || a->tchka == -1)
			return (buf);
	}
	free(buf);
	buf = ft_strnew(0);
	return (buf);
}

char	*for_bits_check_mmm(wint_t ch, t_param *a)
{
	char	*buf;

	buf = ft_strnew(5);
	buf[2] = ((ch & 0x0000003f) | 0x00000080) & 0xffffffbf;
	buf[1] = (((0x00000fc0 & ch) >> 6) | 0x00000080) & 0xffffffbf;
	buf[0] = ((0x0000f000 & ch) >> 12 | 0x000000e0) & 0xffffffef;
	if (ch == 0 && (a->type == 'S' || a->type == 's'))
	{
		free(buf);
		return ("\0");
	}
	else if (a->type == 'C' || a->type == 'c')
	{
		g_iter = g_iter + 3;
		write(1, buf, 3);
	}
	else if (a->type == 's' || a->type == 'S')
	{
		if ((a->prcsn = a->prcsn - 3) >= 0 || a->tchka == -1)
			return (buf);
	}
	free(buf);
	buf = ft_strnew(0);
	return (buf);
}
