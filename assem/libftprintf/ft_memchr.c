/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:51:26 by bgres             #+#    #+#             */
/*   Updated: 2017/11/03 22:49:07 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*a;

	a = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*a == (unsigned char)c)
			return (a);
		i++;
		a++;
	}
	return (NULL);
}
