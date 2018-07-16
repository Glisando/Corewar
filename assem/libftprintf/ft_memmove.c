/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:52:05 by bgres             #+#    #+#             */
/*   Updated: 2017/11/03 22:42:59 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*pd;
	unsigned char	*ps;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (pd <= ps || pd >= (ps + len))
	{
		while (len--)
			*pd++ = *ps++;
	}
	else
	{
		pd += len - 1;
		ps += len - 1;
		while (len--)
			*pd-- = *ps--;
	}
	return (dest);
}
