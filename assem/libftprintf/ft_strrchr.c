/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:31:29 by bgres             #+#    #+#             */
/*   Updated: 2017/11/04 19:15:25 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*a;

	a = NULL;
	while (*str != '\0')
	{
		if (*str == (unsigned char)ch)
			a = (char *)str;
		str++;
	}
	if ((unsigned char)ch == '\0')
		a = (char *)str;
	return (a);
}
