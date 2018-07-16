/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgres <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 12:55:20 by bgres             #+#    #+#             */
/*   Updated: 2017/10/25 14:21:29 by bgres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*d;

	d = (unsigned char *)b;
	if (len != 0)
	{
		while (len-- != 0)
			*d++ = (unsigned char)c;
	}
	return (b);
}
