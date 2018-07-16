/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 23:29:27 by bgres             #+#    #+#             */
/*   Updated: 2018/02/09 23:29:29 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_decimal(t_param **list, va_list vl)
{
	long long	l;
	char		c;
	char		fl;

	if (ft_strchr("DOU", (*list)->type))
	{
		(*list)->type += 32;
		if ((*list)->lm == -1)
			(*list)->lm = 'l';
		else
			(*list)->lm = 'L';
	}
	c = (*list)->type;
	fl = (*list)->lm;
	(c == 'i') ? (c = 'd') : 1;
	(c == 'd' && fl == -1) ? l = (int)va_arg(vl, int) : 1;
	(c == 'd' && fl == 'H') ? l = (signed char)va_arg(vl, int) : 1;
	(c == 'd' && fl == 'h') ? l = (short)va_arg(vl, int) : 1;
	(c == 'd' && fl == 'l') ? l = va_arg(vl, long int) : 1;
	(c == 'd' && fl == 'L') ? l = va_arg(vl, long long) : 1;
	(c == 'd' && fl == 'j') ? l = va_arg(vl, intmax_t) : 1;
	(c == 'd' && fl == 'z') ? l = va_arg(vl, size_t) : 1;
	getd(list, c, l, vl);
}

void	getd(t_param **list, char c, long long l, va_list vl)
{
	char		fl;
	size_t		s;

	fl = (*list)->lm;
	s = 0;
	(c != 'd' && fl == -1) ? s = va_arg(vl, unsigned int) : 1;
	(c != 'd' && fl == 'H') ? s = (unsigned char)va_arg(vl, int) : 1;
	(c != 'd' && fl == 'h') ? s = (unsigned short)va_arg(vl, int) : 1;
	(c != 'd' && fl == 'l') ? s = va_arg(vl, unsigned long) : 1;
	(c != 'd' && fl == 'L') ? s = va_arg(vl, unsigned long long) : 1;
	(c != 'd' && fl == 'j') ? s = va_arg(vl, uintmax_t) : 1;
	(c != 'd' && fl == 'z') ? s = va_arg(vl, size_t) : 1;
	if (c == 'd' && l < 0)
		itoa_printf(-1 * l, (*list), -1);
	else if (c == 'd' && l >= 0)
		itoa_printf(l, (*list), 1);
	else if (c != 'd')
		itoa_printf(s, (*list), 1);
}

size_t	ft_get_len(size_t n, int b)
{
	size_t		i;

	i = 1;
	while (n /= b)
		i++;
	return (i);
}

char	*ft_stranew(size_t size, char *aa)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)ft_memalloc(size + 1);
	while (i < size)
	{
		a[i] = aa[0];
		i++;
	}
	return (a);
}

size_t	get_p(va_list vl)
{
	size_t		s;

	s = va_arg(vl, unsigned long);
	return (s);
}
